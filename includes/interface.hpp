/**
 * @file    interface.hpp
 * @author  Ana Lívia Ruegger Saldanha       8586691
 *          Guilherme Souza Panza           12543519
 *          João Antônio Misson Milhorim    11834331
 *          Maria Victória Brandão Barros   12608692
 * 
 * @brief   Arquivo header para o módulo da interface.
 * 
 * @date    2022-12-19
 * 
 */

#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include <ncurses.h>

void print_title(WINDOW *win);

void print_countdown(WINDOW *win);

void print_end_message(WINDOW *win, int winner, int p1_points, int p2_points);

void print_rules(WINDOW *win);

#endif