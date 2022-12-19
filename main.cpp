/**
 * @file    main.cpp
 * @author  Ana Lívia Ruegger Saldanha       8586691
 *          Guilherme Souza Panza           12543519
 *          João Antônio Misson Milhorim    11834331
 *          Maria Victória Brandão Barros   12608692
 * 
 * @brief   Arquivo principal para execução do jogo Capture the Flag.
 * 
 * @date    2022-12-19
 * 
 */

#include "includes/game.hpp"

int main() {
    Game capture_flag = Game(5);
    capture_flag.execute_game();

    return 0;
}