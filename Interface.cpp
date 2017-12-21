#include "Interface.h"
#include <iostream>

Interface::Interface() {
}

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

Interface::Interface(const Interface& orig) {
}

Interface::~Interface() {
}

