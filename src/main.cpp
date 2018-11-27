/*
 * @Author: Renz 
 * @Date: 2018-11-25 21:19:20 
 * @Last Modified by: Stanley Heryanto
 * @Last Modified time: 2018-11-25 23:25:42
 */
#include "timekeeper.hpp"
#include "screen.hpp"
#include "game.hpp"
#include "counter.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    
    string nama;
    ushort pilihan;
    bool lanjut = true;

    while(lanjut){
        system("clear");
        cout << "Welcome to Terminal Dino\n"
             << "Please play this game on 80x24 terminal\n\n"
             << "1.Play game\n2.View scores\n3.Search player\n4.Exit\n"
             << "Enter choice: ";
        
        do{
            cin >> pilihan;
            cout << "pilihan: " << pilihan << endl;
        }while(pilihan != 1 && pilihan != 2 && pilihan != 3 && pilihan != 4);
        system("clear");

        switch(pilihan){
            case 1:
                cout << "Enter player name: ";
                cin.ignore();
                getline(cin, nama);
                //inisiasi
                initScreen();
                initGame();
                initScore(nama);
                //masuk game loop
                while(isPlaying){
                    moveBlock();
                    handleInput();
                    drawScreen();
                    checkGameOver();
                    sleep(20);
                }
                //game selesai
                finishScreen();
                writeScore();   
                break;
            case 2:
                viewScores();
                break;
            case 3:
                break;
            case 4:
                lanjut = false;
                break;
            }
    }
    return 0;
}