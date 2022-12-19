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
        vector<int> get_keys();
        void set_curr_pos(pair<int, int> pos);
        void move();
        void display();
        pair<int, int> get_curr_pos();
        void reset_points();
};

#endif