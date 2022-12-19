/**
 * @file    flag.hpp
 * @author  Ana Lívia Ruegger Saldanha       8586691
 *          Guilherme Souza Panza           12543519
 *          João Antônio Misson Milhorim    11834331
 *          Maria Victória Brandão Barros   12608692
 * 
 * @brief   Arquivo header para o módulo da classe da bandeira.
 * 
 * @date    2022-12-19
 * 
 */

#ifndef _FLAG_H_
#define _FLAG_H_

#include <iostream>
#include <ncurses.h>
#include <vector>

using namespace std;

class Flag {
    private:
        WINDOW *curr_win;
        char image;
        int n_spawns;
        pair<int, int> curr_pos;
        int max_x;
        int max_y;
        int new_random_x_pos();
        int new_random_y_pos();

    public:
        Flag();
        Flag(WINDOW *win, pair<int, int> pos, char image);
        int get_n_spawns();
        void new_random_pos();
        void display();
        pair<int, int> get_curr_pos();
};

#endif