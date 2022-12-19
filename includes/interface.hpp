#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include <ncurses.h>

void print_title(WINDOW *win);

void print_countdown(WINDOW *win);

void print_end_message(WINDOW *win, int winner, int p1_points, int p2_points);

void print_rules(WINDOW *win);

#endif