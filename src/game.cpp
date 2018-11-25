/*
 * @Author: Renz 
 * @Date: 2018-11-25 22:49:04 
 * @Last Modified by: Stanley Heryanto
 * @Last Modified time: 2018-11-25 23:27:42
 */
#include "game.hpp"

using namespace std;

//struct yang menyimpan posisi dalam koordinat x dan y
struct vec2D {
    uint_fast8_t x;
    uint_fast8_t y;
};

//struct player
struct {
    vec2D pos = {10, 5};
    char disp_char = 'O';
} dino;

int in_char;
bool isPlaying = true;

void handleInput(){
    mvaddch(dino.pos.y, dino.pos.x,' ');
    in_char = wgetch(window);
    switch (in_char){
        case 'q':
            isPlaying = false;
            break;
        case KEY_UP:
        case 'w':
            dino.pos.y -= 1;
            break;
        case KEY_DOWN:
        case 's':
            dino.pos.y += 1;
            break;
        case KEY_LEFT:
        case 'a':
            dino.pos.x -= 1;
            break;
        case KEY_RIGHT:
        case 'd':
            dino.pos.x += 1;
            break;
    }
    mvaddch(dino.pos.y, dino.pos.x, dino.disp_char);
}
