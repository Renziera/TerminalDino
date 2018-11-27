/*
 * @Author: Renz 
 * @Date: 2018-11-25 23:42:16 
 * @Last Modified by:   Stanley Heryanto 
 * @Last Modified time: 2018-11-25 23:42:16 
 */
#include "counter.hpp"

using namespace std;

string namaPemain[100];
unsigned long skorPemain[100];
unsigned short session;     //Berapa kali game telah berlangsung
unsigned long currentScore; //variabel untuk menyimpan skor game skrg
void bubbleSort();  //deklarasi fungsi

void initScore(string nama){
    currentScore = 0; 
    namaPemain[session] = nama;
}

void updateScore(){
    currentScore++;
}

void writeScore(){
    skorPemain[session] = currentScore;
    currentScore = 0;
    session++;
}

void viewScores(){
    cout << "\t\tHigh scores" << endl << endl;
    cout << "\tPlayer Name         \tScore" << endl;
    bubbleSort();
    for(int i = 0; i < session; i++){
        cout << i+1 << "\t" << namaPemain[i] <<  "\t" << skorPemain[i] << endl; 
    }
    if(session == 0){
        cout << endl << "No game been played." << endl;
    }
    cout << endl << "Press enter to return to menu" << endl;
    cin.ignore();
    getchar();
}

//pencarian sequential
void searchPlayer(string name){
    cout << "\nResult for " << name << endl << endl;
    cout << "\tPlayer Name         \tScore" << endl;
    bool found = false;
    bubbleSort();
    for(int i = 0; i < session; i++){
        if(namaPemain[i].find(name) != string::npos){
            cout << i+1 << "\t" << namaPemain[i] <<  "\t" << skorPemain[i] << endl;
            found = true;
        }
    }

    if(!found){
        cout << endl << "Entry not found" << endl;
    }

    cout << endl << "Press enter to return to menu" << endl;
    
    getchar();
}

//Pengurutan descending
void bubbleSort(){
    for(int i = 0; i < session - 1; i++){
        for(int j = 0; j < session - i - 1; j++){
            if(skorPemain[j] < skorPemain[j+1]){
                swap(skorPemain[j], skorPemain[j+1]);
                swap(namaPemain[j], namaPemain[j+1]);
            }
        }
    }
}

//untuk menyimpan skor ke file
void writeToFile(){
    ofstream fileku;
    fileku.open("skor");
    for(int i = 0; i < session; i++){
        fileku << namaPemain[i] << endl;
        fileku << skorPemain[i] << endl;
    }
    fileku.close();
}

void readFromFile(){
    ifstream fileku;
    fileku.open("skor");
    session = 0;
    string temp;
    while(!fileku.eof()){
        getline(fileku, namaPemain[session]);
        getline(fileku, temp);
        skorPemain[session] = stol(temp);
    }
}