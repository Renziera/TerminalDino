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

void bubbleSort(){
    for(int i = 0; i < session; i++){
        for(int j = 1; j < session; j++){
            if(skorPemain[i] < skorPemain[j]){
                swap(skorPemain[i], skorPemain[j]);
            }
        }
    }
}