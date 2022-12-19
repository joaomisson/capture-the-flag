#include "game.hpp"

mutex input_mutex;

char current_player = '0';
vector<int> p1_keys = {'w', 'd', 's', 'a'};
vector<int> p2_keys = {KEY_UP, KEY_RIGHT, KEY_DOWN, KEY_LEFT};

Game::Game(int num_rounds) {
    this->total_rounds = num_rounds;
    this->current_round = 0;
    this->round_over = false;
};

Player Game::init_player(WINDOW *win, pair<int, int> start_pos, char image, vector<int> keys) {
    return Player(win, start_pos, image, keys);
}

Flag Game::init_flag(WINDOW *win, pair<int, int> start_pos, char image) {
    return Flag(win, start_pos, image);
}

void get_current_player(vector<int> keys, WINDOW * win) {
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

void Game::execute_round(WINDOW *win) {
    while (!this->round_over) {
        wclear(win);
        print_countdown(win);
        
        wborder(win, '#', '#', '#', '#', '#', '#', '#', '#');
        this->p1.display();
        this->p2.display();
        this->f.display();
        wrefresh(win);

        while (!this->round_over) {
            thread t_p1(get_current_player, this->p1.get_keys(), win);
            thread t_p2(get_current_player, this->p1.get_keys(), win);
            // thread t_f();

            t_p1.join();
            t_p2.join();
            // t_f.join();
            
            for (int i = 0; i < 10; i++) {
                this->f.display();
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

                wrefresh(win);
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

    WINDOW *game_win = newwin(20, 70, 2, 5);
    refresh();

    print_title(game_win);
    keypad(game_win, true);
    
    string choices[2] = {"Start", "Quit"};

    int input_key = 0, current_choice = 0;
    while (input_key != 10) {
        for (int i = 0; i < 2; i++) {
            if (i == current_choice) {
                wattron(game_win, A_REVERSE);
            }
            mvwprintw(game_win, i + 18, 31, "%s", choices[i].c_str());
            wrefresh(game_win);
            wattroff(game_win, A_REVERSE);
        }
        input_key = wgetch(game_win);

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

    this->p1 = init_player(game_win, make_pair(10, 15), '@', p1_keys);
    this->p2 = init_player(game_win, make_pair(60, 15), '&', p2_keys);
    this->f = init_flag(game_win, make_pair(35, 10), 'P');

    while (this->current_round < this->total_rounds) {
        this->execute_round(game_win);
        this->current_round++;
    }

    int winner;
    if (this->p1.get_points() > this->p2.get_points()) winner = 1;
    else if (this->p1.get_points() < this->p2.get_points()) winner = 2;
    else { winner = 0; }
    print_end_message(game_win, winner);

    getch();
    getch();
    getch();
    getch();


    endwin();  
}