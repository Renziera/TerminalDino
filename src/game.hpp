#ifndef game_hpp
#define game_hpp

#include "screen.hpp"
#include "counter.hpp"
#include <cstdint>
#include<cstdlib>
#include<ctime>

extern bool isPlaying;
void handleInput();
void moveBlock();
void initGame();
void checkGameOver();

#endif