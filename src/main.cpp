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

    system("clear");
    cout << "Welcome to Terminal Dino\n"
         << "Please play this game on 80x24 terminal\n";
    
    initScreen();
    initGame();

    while(isPlaying){
        handleInput();
        moveBlock();
        drawScreen();
        sleep(20);
    }

    mvaddstr(10, 35, "Game Over");
    mvaddstr(11, 33, "Press any key");
    drawScreen();
    getchar();
    finishScreen();
    int x;
    cin >> x;
    return 0;
}