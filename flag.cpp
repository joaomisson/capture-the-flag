#include "flag.hpp"

Flag::Flag() { };

Flag::Flag(WINDOW *win, pair<int, int> pos, char image) {
    this->curr_win = win;
    this->curr_pos = pos;
    this->image = image;
    this->n_spawns = 0;
    getmaxyx(this->curr_win, this->max_y, this->max_x);
}

int Flag::get_n_spawns() {
    return this->n_spawns;
}

pair<int, int> Flag::get_curr_pos() {
    return this->curr_pos;
}

int Flag::new_random_x_pos() {
    int new_x;
    int min = 3;
    int max = this->max_x - 3;
    time_t current_time = time(NULL);
    
    srand((unsigned) current_time);
    new_x = (rand() % (max - min + 1)) + min;

    return new_x;
}

int Flag::new_random_y_pos() {
    int new_y;
    int min = 3;
    int max = this->max_y - 3;
    time_t current_time = time(NULL);
    
    srand((unsigned) current_time);
    new_y = (rand() % (max - min + 1)) + min;
    
    return new_y;
}

void Flag::new_random_pos() {
    this->curr_pos = make_pair(new_random_x_pos(), new_random_y_pos());
}

void Flag::display() {
    mvwaddch(this->curr_win, this->curr_pos.second, this->curr_pos.first, this->image);
}