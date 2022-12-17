#include "character.hpp"
#include <string>
#include <iostream>
#include <thread>
#include <pthread.h>

using namespace std;

WINDOW* game_window;
pthread_mutex_t mutex;

void* player(void* p){

    Player* player_x = (Player*) p;

    do {
        pthread_mutex_lock(&mutex);
        player_x->display();        
        wrefresh(game_window);
        pthread_mutex_unlock(&mutex);
    } while (player_x->move() != 'x');

    return 0;
}

int main() {
    initscr();
    noecho();
    curs_set(0);

    game_window = newwin(20, 70, 2, 5);
    refresh();

    wborder(game_window, '#', '#', '#', '#', '#', '#', '#', '#');
    wrefresh(game_window);
    keypad(game_window, true);

    vector<int> keys_player_one;
    keys_player_one.push_back((int) 'w');
    keys_player_one.push_back((int) 's');
    keys_player_one.push_back((int) 'a');
    keys_player_one.push_back((int) 'd');


    vector<int> keys_player_two;
    keys_player_two.push_back(KEY_UP);
    keys_player_two.push_back(KEY_DOWN);
    keys_player_two.push_back(KEY_LEFT);
    keys_player_two.push_back(KEY_RIGHT);


    //int counter = 0;
    Player* player_one = new Player(game_window, 1, 1, '@', keys_player_one);
    Player *player_two = new Player(game_window, 8, 8, '&', keys_player_two);
    // Character *enemy = new Character(game_window, 15, 15, 'X');

    pthread_mutex_init(&mutex, NULL);
    pthread_t p1, p2;

    pthread_create(&p1, NULL, &player, player_one);
    pthread_create(&p2, NULL, &player, player_two);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    //thread p1(player, player_one, game_window), p2(player, player_two, game_window);
    //thread p2(player, player_two, game_window);
    //p1.join();
    //p2.join();

    /*do {
        player_one->display();
        // player_two->display();
        // enemy->display();
        // enemy->move();
        
        wrefresh(game_window);
        counter++;
    } while (player_one->move() != 'x'); */

    getch();

    endwin();

    pthread_mutex_destroy(&mutex);

    return 0;
}