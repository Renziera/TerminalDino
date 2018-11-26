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
    vec2D pos = {10, 21};
    char disp_char = 'O';
} dino;

struct {
    vec2D pos;
    char disp_char = 'I';
} block1, block2;

int in_char;
bool isPlaying = true;

int jumpTick;
bool isJumping = false;

void handleInput(){
    mvaddch(dino.pos.y, dino.pos.x, ' ');
    mvaddch(dino.pos.y + 1, dino.pos.x, ' ');
    mvaddch(dino.pos.y, dino.pos.x + 1, ' ');
    mvaddch(dino.pos.y + 1, dino.pos.x + 1, ' ');
    in_char = wgetch(window);
    switch (in_char){
        case 'q':
            isPlaying = false;
            break;
        case KEY_UP:
        case 'w':
        case ' ':
            if(dino.pos.y == 21){   //sedang di tanah
                isJumping = true;
                jumpTick = 0;
                beep();
            }
            break;
        case KEY_DOWN:
        case 's':
            if(isJumping && dino.pos.y < 18){
                dino.pos.y += 2;   //ke bawah
            }
            break;
    }

    if(isJumping){

        if(dino.pos.y >= 21 && jumpTick > 1){
            isJumping = false;
            jumpTick = 0;
        }

        jumpTick++;
        if(jumpTick % 2 == 0 && jumpTick < 25){
            dino.pos.y--;      //ke atas
        }
        
        if(jumpTick % 2 == 0 && jumpTick > 25){
            dino.pos.y++;   //ke bawah
        }

        if(jumpTick > 48){
            isJumping = false;
            jumpTick = 0;
        }

    }

    mvaddch(dino.pos.y, dino.pos.x, dino.disp_char);
    mvaddch(dino.pos.y + 1, dino.pos.x, dino.disp_char);
    mvaddch(dino.pos.y, dino.pos.x + 1, dino.disp_char);
    mvaddch(dino.pos.y + 1, dino.pos.x + 1, dino.disp_char);
}

void moveBlock(){
    mvaddch(block1.pos.y, block1.pos.x, ' ');
}

bool isGameOver(){

}