/*
 * @Author: Renz 
 * @Date: 2018-11-25 21:19:20 
 * @Last Modified by: Stanley Heryanto
 * @Last Modified time: 2018-11-25 23:25:42
 */
#include "timekeeper.hpp"
#include "screen.hpp"
#include "game.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    initScreen();
    
    while(isPlaying){
        handleInput();
        drawScreen();
        sleep(10);
    }

    finishScreen();
    return 0;
}