#include "player.hpp"

enum directions {UP, RIGHT, DOWN, LEFT};

Player::Player() { };

Player::Player(WINDOW *win, pair<int, int> pos, char image, vector<int> keys) {
    this->curr_win = win;
    this->curr_pos = pos;
    this->image = image;
    this->move_keys = keys;
    this->points = 0;
    getmaxyx(this->curr_win, this->max_y, this->max_x);
}

void Player::add_points(int points) {
    this->points += points;
}

int Player::get_points() {
    return this->points;
}

char Player::get_image() {
    return this->image;
};

pair<int, int> Player::get_curr_pos() {
    return this->curr_pos;
}

vector<int> Player::get_keys() {
    return this->move_keys;
}

void Player::set_curr_pos(pair<int, int> pos) {
    this->curr_pos = pos;
}

void Player::move_up() {
    mvwaddch(this->curr_win, this->curr_pos.second, this->curr_pos.first, ' ');
    this->curr_pos.second--;
    if (this->curr_pos.second < 1) this->curr_pos.second = 1;
}

void Player::move_right() {
    mvwaddch(this->curr_win, this->curr_pos.second, this->curr_pos.first, ' ');
    this->curr_pos.first++;
    if (this->curr_pos.first > max_x - 2) this->curr_pos.first = max_x - 2;
}

void Player::move_down() {
    mvwaddch(this->curr_win, this->curr_pos.second, this->curr_pos.first, ' ');
    this->curr_pos.second++;
    if (this->curr_pos.second > max_y - 2) this->curr_pos.second = max_y - 2;
}

void Player::move_left() {
    mvwaddch(this->curr_win, this->curr_pos.second, this->curr_pos.first, ' ');
    this->curr_pos.first--;
    if (this->curr_pos.first < 1) this->curr_pos.first = 1;
}

void Player::move() {
    int input_key = wgetch(this->curr_win);

    if (input_key == this->move_keys[UP]) move_up();
    else if (input_key == move_keys[RIGHT]) move_right();
    else if (input_key == move_keys[DOWN]) move_down();
    else if (input_key == move_keys[LEFT]) move_left();
}

void Player::display() {
    mvwaddch(this->curr_win, this->curr_pos.second, this->curr_pos.first, this->image);
}

void Player::reset_points() {
    this->points = 0;
}
