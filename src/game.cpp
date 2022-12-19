/**
 * @file    game.cpp
 * @author  Ana Lívia Ruegger Saldanha       8586691
 *          Guilherme Souza Panza           12543519
 *          João Antônio Misson Milhorim    11834331
 *          Maria Victória Brandão Barros   12608692
 * 
 * @brief   Módulo contendo as funções ligadas à classe do jogo.
 * 
 * @date    2022-12-19
 * 
 */

#include "../includes/game.hpp"

mutex input_mutex;

char current_player = '0';
vector<int> p1_keys = {'w', 'd', 's', 'a'};
vector<int> p2_keys = {KEY_UP, KEY_RIGHT, KEY_DOWN, KEY_LEFT};

Game::Game(int num_rounds) {
    this->total_rounds = num_rounds;
    this->current_round = 0;
    this->round_over = false;
};

Player Game::init_player(pair<int, int> start_pos, char image, vector<int> keys) {
    return Player(this->curr_win, start_pos, image, keys);
}

Flag Game::init_flag(pair<int, int> start_pos, char image) {
    return Flag(this->curr_win, start_pos, image);
}

void get_current_player(vector<int> keys, WINDOW *win) {
    int input_key = 0;
    input_mutex.lock();

    while (!count(keys.begin(), keys.end(), input_key)) {
        if (current_player != '0') {
            input_mutex.unlock();
            return;
        }

        input_key = wgetch(win);
        if (count(p1_keys.begin(), p1_keys.end(), input_key)) {
            current_player = '1';
        } else if (count(p2_keys.begin(), p2_keys.end(), input_key)) {
            current_player = '2';
        }
    }
    
    input_mutex.unlock();
    return;
}

void Game::execute_round() {
    while (!this->round_over) {
        wclear(this->curr_win);
        print_countdown(this->curr_win);
        
        wborder(this->curr_win, '#', '#', '#', '#', '#', '#', '#', '#');
        this->p1.display();
        this->p2.display();
        this->f.display();
        wrefresh(this->curr_win);

        while (!this->round_over) {
            thread t_p1(get_current_player, this->p1.get_keys(), this->curr_win);
            thread t_p2(get_current_player, this->p1.get_keys(), this->curr_win);

            t_p1.join();
            t_p2.join();
            
            for (int i = 0; i < 10; i++) {
                if (current_player == '1') {
                    this->p1.move();
                    this->p1.display();
                    if (this->f.get_curr_pos() == this->p1.get_curr_pos()) {
                        this->f.new_random_pos();
                        this->p1.add_points(1);
                        this->round_over = true;
                    }
                } else if (current_player == '2') {
                    this->p2.move();
                    this->p2.display();
                    if (this->f.get_curr_pos() == this->p2.get_curr_pos()) {
                        this->f.new_random_pos();
                        this->p2.add_points(1);
                        this->round_over = true;
                    }
                }

                if (this->round_over) break;
                wrefresh(this->curr_win);
            }

            current_player = '0';
        }
    }

    this->round_over = false;
    this->p1.set_curr_pos(make_pair(10, 15));
    this->p2.set_curr_pos(make_pair(60, 15));
}

void Game::execute_game() {
    initscr();
    noecho();
    curs_set(0);

    this->curr_win = newwin(20, 70, 2, 5);
    refresh();

    print_title(this->curr_win);
    keypad(this->curr_win, true);
    
    string choices[2] = {"Start", "Quit"};

    int input_key = 0, current_choice = 0;
    while (input_key != 10) {
        for (int i = 0; i < 2; i++) {
            if (i == current_choice) {
                wattron(this->curr_win, A_REVERSE);
            }
            mvwprintw(this->curr_win, i + 18, 31, "%s", choices[i].c_str());
            wrefresh(this->curr_win);
            wattroff(this->curr_win, A_REVERSE);
        }
        input_key = wgetch(this->curr_win);

        switch (input_key) {
            case KEY_UP:
                current_choice--;
                if (current_choice == -1) current_choice = 0;
                break;
            
            case KEY_DOWN:
                current_choice++;
                if (current_choice == 2) current_choice = 1; 
                break;
        }
    }

    if (choices[current_choice] == "Quit") {
        endwin();
        return;
    }

    print_rules(this->curr_win);

    this->p1 = init_player(make_pair(10, 15), '@', p1_keys);
    this->p2 = init_player(make_pair(60, 15), '&', p2_keys);
    this->f = init_flag(make_pair(35, 10), 'P');

    while (this->current_round < this->total_rounds) {
        this->execute_round();
        this->current_round++;
    }

    int winner;
    if (this->p1.get_points() > this->p2.get_points()) winner = 1;
    else if (this->p1.get_points() < this->p2.get_points()) winner = 2;
    else { winner = 0; }
    print_end_message(this->curr_win, winner, this->p1.get_points(), this->p2.get_points());
    napms(1000);

    endwin();  
}