#ifndef counter_hpp
#define counter_hpp

#include <string>
#include <iostream>

extern unsigned long currentScore;
void updateScore();
void initScore(std::string);
void writeScore();
void viewScores();

#endif