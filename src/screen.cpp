/*
 * @Author: Renz 
 * @Date: 2018-11-25 21:19:28 
 * @Last Modified by: Stanley Heryanto
 * @Last Modified time: 2018-11-25 22:03:49
 */
#include "screen.hpp"
#include <ncurses.h>
#include <iostream>

using namespace std;

WINDOW* window;

void initScreen(){
    window = initscr();     //masuk mode ncurses
    cbreak();   //gak nunggu newline untuk getch()
    noecho();   //key yang ditekan tidak muncul di layar
    clear();
    refresh();
    keypad(window, true);   //supaya gak ngeprint escape sequence action key
    nodelay(window, true);  //supaya gak nunggu input
    curs_set(0);    //invincible cursor

    if(!has_colors()) {
        endwin();
        cout << "Terminal tidak support warna." << endl;
    }

    start_color();

    attron(A_BOLD);     //aktifkan atribut bold
    box(window, 0, 0);  //gambar kotak
    attroff(A_BOLD);    //non-aktifkan atribut bold

    init_pair(1, COLOR_BLACK, COLOR_BLUE);      //deklarasi warna
    wbkgd(window, COLOR_PAIR(1));               //set warna
}

void drawScreen(){
    refresh();
}

void finishScreen(){
    endwin();   //keluar mode ncurses
}