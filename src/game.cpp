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

//struct kaktus (ceritanya)
struct {
    vec2D pos = {100, 20};  //sengaja di luar arena
    char disp_char = 'I';
} block1, block2;

bool block1Ready = true;    //ready berarti lagi gak di layar
bool block2Ready = true;

void initGame(){
    srand(time(NULL));
    isPlaying = true;
    block1Ready = true;
    block2Ready = true;
    block1.pos = {100, 20};
    block2.pos = {100, 20};
    dino.pos = {10, 21};
}

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
    //clear all blocks
    mvaddch(block1.pos.y, block1.pos.x, ' ');
    mvaddch(block1.pos.y, block1.pos.x + 1, ' ');
    mvaddch(block1.pos.y + 1, block1.pos.x, ' ');
    mvaddch(block1.pos.y + 2, block1.pos.x, ' ');
    mvaddch(block1.pos.y + 1, block1.pos.x + 1, ' ');
    mvaddch(block1.pos.y + 2, block1.pos.x + 1, ' ');

    mvaddch(block2.pos.y, block2.pos.x, ' ');
    mvaddch(block2.pos.y, block2.pos.x + 1, ' ');
    mvaddch(block2.pos.y + 1, block2.pos.x, ' ');
    mvaddch(block2.pos.y + 2, block2.pos.x, ' ');
    mvaddch(block2.pos.y + 1, block2.pos.x + 1, ' ');
    mvaddch(block2.pos.y + 2, block2.pos.x + 1, ' ');

    //gerakin blocks
    if(block1Ready){
        if(rand() % 8 == 0){
            block1.pos.x = rand() % 100 + 100;  //instantiate di kanan arena
            block1Ready = false;
        }
    }else{
        block1.pos.x--;
        if(block1.pos.x < 1){     //sudah di luar arena
            block1.pos.x = 100;     //buang keluar arena
            block1Ready = true;
        }
    }

    if(block2Ready){
        if(rand() % 8 == 0){
            block2.pos.x = rand() % 100 + 100;  //instantiate di kanan arena
            block2Ready = false;
        }
    }else{
        block2.pos.x--;
        if(block2.pos.x < 1){     //sudah di luar arena
            block2.pos.x = 100;     //buang keluar arena
            block2Ready = true;
        }
    }


    //draw blocks
    mvaddch(block1.pos.y, block1.pos.x, block1.disp_char);
    mvaddch(block1.pos.y, block1.pos.x + 1, block1.disp_char);
    mvaddch(block1.pos.y + 1, block1.pos.x, block1.disp_char);
    mvaddch(block1.pos.y + 2, block1.pos.x, block1.disp_char);
    mvaddch(block1.pos.y + 1, block1.pos.x + 1, block1.disp_char);
    mvaddch(block1.pos.y + 2, block1.pos.x + 1, block1.disp_char);

    mvaddch(block2.pos.y, block2.pos.x, block2.disp_char);
    mvaddch(block2.pos.y, block2.pos.x + 1, block2.disp_char);
    mvaddch(block2.pos.y + 1, block2.pos.x, block2.disp_char);
    mvaddch(block2.pos.y + 2, block2.pos.x, block2.disp_char);
    mvaddch(block2.pos.y + 1, block2.pos.x + 1, block2.disp_char);
    mvaddch(block2.pos.y + 2, block2.pos.x + 1, block2.disp_char);
}

void checkGameOver(){
    //only check at collision site
    if(block1.pos.x == 9 || block1.pos.x == 10 || block1.pos.x == 11){
        if(
            block1.pos.y == dino.pos.y + 1 ||
            block1.pos.y + 1 == dino.pos.y + 1 ||
            block1.pos.y + 2 == dino.pos.y + 1
            ){
            isPlaying = false;
            beep();
            beep();
            beep();
            return;
        }
    }

    if(block2.pos.x == 9 || block2.pos.x == 10 || block2.pos.x == 11){
        if(
            block2.pos.y == dino.pos.y + 1 ||
            block2.pos.y + 1 == dino.pos.y + 1 ||
            block2.pos.y + 2 == dino.pos.y + 1
            ){
            isPlaying = false;
            beep();
            beep();
            beep();
            return;
        }
    }

    //nambah skor
    updateScore();
    mvaddstr(2, 67, to_string(currentScore).c_str());
}