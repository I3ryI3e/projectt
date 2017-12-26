#include "Interface.h"
#include <iostream>

void Interface::initial_screen(){
    Consola::setScreenSize(30, 120);
    Consola::setTextColor(Consola::VERDE_CLARO);
}

void Interface::screen_config_stage(){
    Consola::gotoxy(20, 14);
    cout << "Bem vindo ao programa de simulacao de populacoes de formigas" << endl;
    Consola::gotoxy(20, 15);
    cout << "Trabalho pratico de POO 2017/2018" << endl;
    Consola::gotoxy(20, 16);
    cout << "Comando: ";
}

void Interface::printborders(int lim){
    int i, j, l=0, c=0, k=-3;
    for(i=-2;i<=lim;i++){
        for(j=119;j>=(117-lim);j--, k+=2){
            Consola::setTextColor(Consola::BRANCO_CLARO);
            Consola::gotoxy(j, i+2);
            if(i==-2 && j<=117 && j>(117-lim)){
                Consola::gotoxy(j-lim+k, 0);
                cout << c++;
                if(c==10)
                    c=0;
                continue;
            }
            if(j==119 && i>=0 && i<lim){
                cout << l++;
                if(l==10)
                    l=0;
                continue;
            }
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
            if(i==-1 && j!=119){
                cout << (char)205;
                continue;
            }
            if(j==118 && i!=-2){
                cout << (char)186;
                continue;
            }
            if(i==lim && j!=119){
                cout << (char)205;
                continue;
            }
            if(j==(117-lim) && i!=-2){
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
    Consola::gotoxy(aux.getX()+(118-lim), aux.getY()+2);
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

void Interface::mostrainfo(string aux){
    cout << aux;
}

void Interface::clrscreen(){
    Consola::clrscr();
}