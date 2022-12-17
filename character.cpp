#include "character.hpp"

enum directions{UP, DOWN, LEFT, RIGHT};

Character::Character(WINDOW *win, int start_x, int start_y, char type) {
    std::srand(time(NULL));
    this->win = win;
    this->x_pos = start_x;
    this->y_pos = start_y;
    this->type = type;
    getmaxyx(win, this->max_y, this->max_x);
}

void Character::move_up() {
    mvwaddch(win, y_pos, x_pos, ' ');
    y_pos--;
    if (y_pos < 1)  y_pos = 1;
}

void Character::move_down() {
    mvwaddch(win, y_pos, x_pos, ' ');
    y_pos++;
    if (y_pos > max_y - 2)  y_pos = max_y - 2;
}

void Character::move_left() {
    mvwaddch(win, y_pos, x_pos, ' ');
    x_pos--;
    if (x_pos < 1)  x_pos = 1;
}

void Character::move_right() {
    mvwaddch(win, y_pos, x_pos, ' ');
    x_pos++;
    if (x_pos > max_x - 2)  x_pos = max_x - 2;
}

void Character::display() {
    mvwaddch(win, y_pos, x_pos, type);
}

int Character::move() {
    int direction = rand() % 4;

    switch (direction) {
        case UP:
            move_up();
            break;
        
        case DOWN:
            move_down();
            break;

        case LEFT:
            move_left(); 
            break;

        case RIGHT:
            move_right();
            break;
    }

    return direction;
}

WINDOW *Character::get_window() {
    return win;
}

Player::Player(WINDOW *win, int start_x, int start_y, char type, vector<int> keys): 
                Character(win, start_x, start_y, type) {
    this->control_keys = keys;
}

int Player::move() {
    int key = wgetch(get_window());

    if (key == control_keys[UP]) {
        move_up();
    } else if (key == control_keys[DOWN]) {
        move_down();
    } else if (key == control_keys[LEFT]) {
        move_left();
    } else if (key == control_keys[RIGHT]) {
        move_right();
    }
    else{ }

    return key;
}