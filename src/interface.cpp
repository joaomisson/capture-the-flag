/**
 * @file    interface.cpp
 * @author  Ana Lívia Ruegger Saldanha       8586691
 *          Guilherme Souza Panza           12543519
 *          João Antônio Misson Milhorim    11834331
 *          Maria Victória Brandão Barros   12608692
 * 
 * @brief   Módulo contendo as funções ligadas à interface.
 * 
 * @date    2022-12-19
 * 
 */

#include <ncurses.h>
#include <string>

using namespace std;

void print_title(WINDOW *win) {
   wprintw(win, R"(
                   ______            __                
                  / ____/___ _____  / /___  __________ 
                 / /   / __ `/ __ \/ __/ / / / ___/ _ \
                / /___/ /_/ / /_/ / /_/ /_/ / /  /  __/
                \____/\__,_/ .___/\__/\__,_/_/   \___/ 
                          /_/__  __                    
                            / /_/ /_  ___              
                           / __/ __ \/ _ \
                          / /_/ / / /  __/             
                          \__/_/ /_/\___/              
                         ________                      
                        / ____/ /___ _____ _           
                       / /_  / / __ `/ __ `/           
                      / __/ / / /_/ / /_/ /            
                     /_/   /_/\__,_/\__, /             
                                   /____/    
    )");
    wrefresh(win);
}

void print_rules(WINDOW *win) {
  wclear(win);
  wprintw(win, R"(                                                                                                        
                _ __    ___    __ _   _ __    __ _   ___ 
              | '__|  / _ \  / _` | | '__|  / _` | / __|
              | |    |  __/ | (_| | | |    | (_| | \__ \
              |_|     \___|  \__, | |_|     \__,_| |___/
                              __/ |                     
                              |___/                                   
                                                                    
    O jogo possui 10 rodadas. A cada rodada uma bandeira
    aparecere em um local aleatoria do campo. O objetivo dos
    jogadores deve ser pegar a bandeira antes do seu inimigo.
    Quem pegar a bandeira primeiro ganha uma rodada. Quem ganhar
    mais rodadas ganha o jogo.

    === JOGADOR 1 ===  |  ==== JOGADOR 2 === | === BANDEIRA ===
     > Simbolo: @      |   > Simbolo: &      |  > Simbolo: P
     > Teclas: WASD    |   > Teclas: Setas   |                               
    )");
    wrefresh(win);
    napms(15000);
    wclear(win);
}


void print_countdown(WINDOW *win) {
    wprintw(win, R"(





                                   _____
                                  |__  /
                                   /_ < 
                                 ___/ / 
                                /____/
    )");
    wrefresh(win);
    napms(1000);
    wclear(win);
    wprintw(win, R"(





                                   ___  
                                  |__ \
                                  __/ / 
                                 / __/  
                                /____/
    )");
    wrefresh(win);
    napms(1000);
    wclear(win);
    wprintw(win, R"(





                                   ___  
                                  <  /  
                                  / /   
                                 / /    
                                /_/
    )");
    wrefresh(win);
    napms(1000);
    wclear(win);
    wrefresh(win);
}

void print_end_message(WINDOW *win, int winner, int p1_points, int p2_points) {
  if (winner == 1) {
    wclear(win);
    wprintw(win, R"(

      
              ___                       _               __  
              |_  |                     | |             /  | 
                | | ___   __ _  __ _  __| | ___  _ __   `| | 
                | |/ _ \ / _` |/ _` |/ _` |/ _ \| '__|   | | 
            /\__/ / (_) | (_| | (_| | (_| | (_) | |     _| |_
            \____/ \___/ \__, |\__,_|\__,_|\___/|_|     \___/
                          __/ |                              
                        |___/                               
                  _   _                             _       
                  | | | |                           | |      
                  | | | | ___ _ __   ___ ___ _   _  | |      
                  | | | |/ _ \ '_ \ / __/ _ \ | | | | |      
                  \ \_/ /  __/ | | | (_|  __/ |_| | |_|      
                   \___/ \___|_| |_|\___\___|\__,_| (_)

    )");
    mvwprintw(win, 18, 0, "JOGADOR 1: %d Pontos", p1_points);
    mvwprintw(win, 19, 0, "JOGADOR 2: %d Pontos", p2_points);
    wrefresh(win);
    napms(10000);
    wclear(win);
  }
  else if (winner == 2) {
    wclear(win);
    wprintw(win, R"(

            ___                       _               _____ 
            |_  |                     | |             / __  \
              | | ___   __ _  __ _  __| | ___  _ __   `' / /'
              | |/ _ \ / _` |/ _` |/ _` |/ _ \| '__|    / /  
          /\__/ / (_) | (_| | (_| | (_| | (_) | |     ./ /___
          \____/ \___/ \__, |\__,_|\__,_|\___/|_|     \_____/
                        __/ |                                
                      |___/                                 
                _   _                             _         
                | | | |                           | |        
                | | | | ___ _ __   ___ ___ _   _  | |        
                | | | |/ _ \ '_ \ / __/ _ \ | | | | |        
                \ \_/ /  __/ | | | (_|  __/ |_| | |_|        
                 \___/ \___|_| |_|\___\___|\__,_| (_)        
                                                                                     
    )");
    mvwprintw(win, 18, 0, "JOGADOR 1: %d Pontos", p1_points);
    mvwprintw(win, 19, 0, "JOGADOR 2: %d Pontos", p2_points);
    wrefresh(win);
    napms(10000);
    wclear(win);
  }
  else {
    wclear(win);
    wprintw(win, R"(





              _____                      _          _ 
              |  ___|                    | |        | |
              | |__ _ __ ___  _ __   __ _| |_ ___   | |
              |  __| '_ ` _ \| '_ \ / _` | __/ _ \  | |
              | |__| | | | | | |_) | (_| | ||  __/  |_|
              \____/_| |_| |_| .__/ \__,_|\__\___|  (_)
                            | |                       
                            |_|          
          
    )");
    mvwprintw(win, 18, 0, "JOGADOR 1: %d Pontos", p1_points);
    mvwprintw(win, 19, 0, "JOGADOR 2: %d Pontos", p2_points);
    wrefresh(win);
    napms(10000);
    wclear(win);
  }
}