#ifndef screen_hpp
#define screen_hpp

#include <ncurses.h>
#include <iostream>

//variable global
extern WINDOW* window;

void initScreen();
void drawScreen();
void finishScreen();

#endif