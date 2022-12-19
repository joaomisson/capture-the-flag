// #include "character.hpp"

#include "game.hpp"

int main() {
    Game capture_flag = Game(2);
    capture_flag.execute_game();
    // initscr();
    // noecho();
    // curs_set(0);

    // WINDOW *game_window = newwin(20, 70, 2, 5);
    // refresh();

    // wborder(game_window, '#', '#', '#', '#', '#', '#', '#', '#');
    // wrefresh(game_window);
    // keypad(game_window, true);

    // vector<int> keys_player_one;
    // keys_player_one.push_back((int) 'w');
    // keys_player_one.push_back((int) 's');
    // keys_player_one.push_back((int) 'a');
    // keys_player_one.push_back((int) 'd');


    // vector<int> keys_player_two;
    // keys_player_two.push_back(KEY_UP);
    // keys_player_two.push_back(KEY_DOWN);
    // keys_player_two.push_back(KEY_LEFT);
    // keys_player_two.push_back(KEY_RIGHT);


    // int counter = 0;
    // Player *player_one = new Player(game_window, 1, 1, '@', keys_player_one);
    // // Player *player_two = new Player(game_window, 8, 8, '&', keys_player_two);
    // // Character *enemy = new Character(game_window, 15, 15, 'X');

    // do {
    //     player_one->display();
    //     // player_two->display();
    //     // enemy->display();
    //     // enemy->move();
        
    //     wrefresh(game_window);
    //     counter++;
    // } while (player_one->move() != 'x');

    // getch();

    // endwin();

    return 0;
}