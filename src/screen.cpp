/*
 * @Author: Renz 
 * @Date: 2018-11-25 21:19:28 
 * @Last Modified by: Stanley Heryanto
 * @Last Modified time: 2018-11-25 23:43:56
 */
#include "screen.hpp"

using namespace std;

WINDOW* window;

void initScreen(){
    //Program ini berasumsi terminal memiliki default size 80x24
    window = initscr();     //masuk mode ncurses
    cbreak();   //gak nyari newline untuk getch()
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

    mvaddstr(1, 33, "Terminal Dino");
    mvaddstr(2, 2, "Press Q to quit");
    mvaddstr(3, 2, "Space or UP to jump");
    mvaddstr(2, 60, "Score:");
}

void drawScreen(){
    box(window, 0, 0);
    refresh();      //meng-update layar asli dengan buffer
}

void finishScreen(){
    endwin();   //keluar mode ncurses
}