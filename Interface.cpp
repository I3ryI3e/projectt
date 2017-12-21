#include "Interface.h"
#include <iostream>

void Interface::setconfig_screen(){
    Consola::setTextColor(Consola::VERDE_CLARO);
    Consola::clrscr();
    Consola::setScreenSize(30, 120);
    Consola::gotoxy(20, 14);
    cout << "Bem vindo ao programa de simulacao de populacoes de formigas" << endl;
    Consola::gotoxy(20, 15);
    cout << "Trabalho pratico de POO 2017/2018" << endl;
    Consola::gotoxy(20, 16);
    cout << "Comando: ";
}

void Interface::printborders(int lim){
    int i, j;
    for(i=-1;i<=lim;i++){
        for(j=118;j>=(117-lim);j--){
            Consola::setTextColor(Consola::BRANCO_CLARO);
            Consola::gotoxy(j, 0+i+1);
            if(i==-1 && j==118){
                cout << (char)187;
                continue;
            }
            if(i==lim && j==118){
                cout << (char)188;
                continue;
            }
            if(i==-1 && j==(117-lim)){
                cout << (char)201;
                continue;
            }
            if(i==lim && j==(117-lim)){
                cout << (char)200;
                continue;
            }
            if(i==-1){
                cout << (char)205;
                continue;
            }
            if(j==118){
                cout << (char)186;
                continue;
            }
            if(i==lim){
                cout << (char)205;
                continue;
            }
            if(j==(117-lim)){
                cout << (char)186;
                continue;
            }
            cout << (char)255;
        }
        cout << endl;
    }
}

void Interface::printcaracter(Ponto aux, int i, int car, int lim){
    Consola::setTextColor(Consola::VERDE+i);
    Consola::gotoxy(aux.getX()+(118-lim), aux.getY()+1);
    cout << (char)car;
    Consola::gotoxy(0,0);
}

string Interface::getlinha(){
    string lin;
    Consola::setTextColor(Consola::VERDE_CLARO);
    getline(cin, lin);
    Consola::clrscr();
    Consola::gotoxy(0,1);
    return lin;
}