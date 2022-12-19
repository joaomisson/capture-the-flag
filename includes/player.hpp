/**
 * @file    player.hpp
 * @author  Ana Lívia Ruegger Saldanha       8586691
 *          Guilherme Souza Panza           12543519
 *          João Antônio Misson Milhorim    11834331
 *          Maria Victória Brandão Barros   12608692
 * 
 * @brief   Arquivo header para o módulo da classe do jogador.
 * 
 * @date    2022-12-19
 * 
 */

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iostream>
#include <ncurses.h>
#include <vector>

using namespace std;

class Player {
    private:
        WINDOW *curr_win;
        char image;
        int points;
        pair<int, int> curr_pos;
        int max_x;
        int max_y;
        vector<int> move_keys;

        void move_up();
        void move_right();
        void move_down();
        void move_left();

    public:
        Player();
        Player(WINDOW *win, pair<int, int> pos, char image, vector<int> move_keys);
        void add_points(int points);
        int get_points();
        char get_image();
        pair<int, int> get_curr_pos();
        vector<int> get_keys();
        void set_curr_pos(pair<int, int> pos);
        void move();
        void display();
        void reset_points();
};

#endif