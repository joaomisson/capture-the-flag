#ifndef _GAME_H_
#define _GAME_H_

#include "interface.hpp"
#include "player.hpp"
#include "flag.hpp"

#include <string>
#include <pthread.h>
#include <thread>
#include <mutex>
#include <algorithm>

class Game {
    private:
        int total_rounds;
        int current_round;
        bool round_over;
        Player p1;
        Player p2;
        Flag f;
        WINDOW *curr_win;

        Player init_player(pair<int, int> start_pos, char image, vector<int> keys);
        Flag init_flag(pair<int, int> pos, char image);      
        void execute_round();
    
    public:
        Game(int num_rounds);
        void execute_game();
};

#endif