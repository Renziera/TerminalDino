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

    readFromFile();

    while(lanjut){
        system("clear");
        cout << "Welcome to Terminal Dino\n"
             << "Please play this game on 80x24 terminal\n\n"
             << "1.Play game\n2.View scores\n3.Search player\n4.Reset Score\n5.Exit\n";
        
        do{
            if(cin.fail()){
                cin.clear();
                cin.ignore();
            }
            cout << "Enter choice: ";
            cin >> pilihan; 
        }while(pilihan != 1 && pilihan != 2 && pilihan != 3 && pilihan != 4 && pilihan != 5);
        system("clear");

        switch(pilihan){
            case 1:
                cout << "Play Terminal Dino" << endl << endl;
                cout << "Enter player name: ";
                cin.ignore();
                getline(cin, nama);
                nama.resize(20, ' ');   //nama di limit 20 char
                cout << "Get ready!" << endl;
                for(int i = 3; i > 0; i--){
                    sleep(500);
                    cout << i << "..." << endl;
                    beep();
                }
                sleep(200);
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
                cout << "Player search" << endl;
                cout << "Enter player name: ";
                cin.ignore();
                getline(cin, nama);
                searchPlayer(nama);
                break;
            case 4:
                resetScore();
                break;
            case 5:
                lanjut = false;
                writeToFile();
                cout << "Thank you for playing!" << endl;
                sleep(500);
                cout << "Have a good day :D" << endl;
                sleep(1000);
                system("clear");
                break;
        }
    }
    return 0;
}