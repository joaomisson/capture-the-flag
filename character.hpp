#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <ncurses.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Character {
    private:
        WINDOW *win;
        int x_pos;
        int max_x;
        int y_pos;
        int max_y;
        char type;

    public:
        Character(WINDOW *win, int start_x, int start_y, char type);
        void move_up();
        void move_down();
        void move_left();
        void move_right();
        void display();
        int move();
        WINDOW *get_window();
};

class Player : public Character{
    private:
        vector<int> control_keys;
    public:
        Player(WINDOW *win, int start_x, int start_y, char type, vector<int> keys);
        int move();
};

#endif