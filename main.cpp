#include "character.hpp"
#include <string>
#include <iostream>
#include <thread>
#include <pthread.h>
#include <unistd.h>
#include <algorithm>
#include<chrono>

using namespace std;

WINDOW* game_window;
pthread_mutex_t mutex;
FILE *log_jogo;

char current_player = '0';
bool selected_player = false;
vector<int> p1_keys = {'w', 's', 'a', 'd'};
vector<int> p2_keys = {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT};

void *get_current_player(void *control_keys) {
    vector<int> *keys = (vector<int>*) control_keys;
    int key = 'h';
    pthread_mutex_lock(&mutex);

    while (!count(keys->begin(), keys->end(), key)) {
        if (selected_player) {
            pthread_mutex_unlock(&mutex);
            return 0;
        }

        key = wgetch(game_window);
        if (count(p1_keys.begin(), p1_keys.end(), key)) {
            current_player = '1';
            selected_player = true;
        } else if (count(p2_keys.begin(), p2_keys.end(), key)) {
            current_player = '2';
            selected_player = true;
        }
    }

    // printw("aaaaaaaaaaaaaaaaaaaaaaa");
    // refresh();
    
    pthread_mutex_unlock(&mutex);
    return 0;
}

void* player(void* p){
    // int m;

    Player* player_x = (Player*) p;
    if (player_x->get_type() == '@') {
        fprintf(log_jogo, "Thread do Player 1\n");
    } else if (player_x->get_type() == '&') {
        fprintf(log_jogo, "Thread do Player 2\n");
    }

    player_x->display();

    //pthread_mutex_lock(&mutex);

    // while (m != 'x'){
        //pthread_mutex_unlock(&mutex);
        pthread_mutex_lock(&mutex);
        player_x->move();
        player_x->display();        
        wrefresh(game_window);
        //sleep(0.1);
        pthread_mutex_unlock(&mutex);
    // };
    napms(1);

    return 0;
}

void fazer(Player *p) {
    for (int i = 0; i < 10; i++) { 
        p->move();
        p->display(); 
        wrefresh(game_window);
    } 
}

int main() {
    log_jogo = fopen("log_jogo.txt", "w");
    initscr();
    cbreak(); // debug
    noecho();
    curs_set(0);

    game_window = newwin(20, 70, 2, 5);
    refresh();

    wborder(game_window, '#', '#', '#', '#', '#', '#', '#', '#');
    wrefresh(game_window);
    keypad(game_window, true);

    //int counter = 0;
    Player* player_one = new Player(game_window, 1, 1, '@', p1_keys);
    Player *player_two = new Player(game_window, 8, 8, '&', p2_keys);

    // Character *enemy = new Character(game_window, 15, 15, 'X');
    pthread_mutex_init(&mutex, NULL);
    pthread_t p2, p1;
    // fprintf(log_jogo, "escreve sla");

    player_one->display();
    player_two->display();

    for (int i = 0; i < 10000000; i++) {
        // printw("bb");
        pthread_create(&p1, NULL, &get_current_player, &p1_keys);
        pthread_create(&p2, NULL, &get_current_player, &p2_keys);

        pthread_join(p1, NULL);
        pthread_join(p2, NULL);

        fprintf(log_jogo, "Ganhou: %c\n", current_player);
        printw("player %c se move!!!", current_player);
        refresh();
        if (current_player == '1') fazer(player_one);
        else if (current_player == '2') fazer(player_two);

        selected_player = false;
        current_player = '0';
    }


    getch();

    endwin();

    pthread_mutex_destroy(&mutex);
    fclose(log_jogo);

    return 0;
}