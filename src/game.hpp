#ifndef game_hpp
#define game_hpp

#include "screen.hpp"
#include <cstdint>
#include<cstdlib>
#include<ctime>

extern bool isPlaying;
void handleInput();
void moveBlock();
void initGame();

#endif