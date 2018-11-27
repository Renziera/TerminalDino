#ifndef counter_hpp
#define counter_hpp

#include <string>

extern unsigned long currentScore;
void updateScore();
void initScore(std::string);
void writeScore();
#endif