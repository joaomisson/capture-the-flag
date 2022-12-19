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