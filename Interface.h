#ifndef INTERFACE_H
#define INTERFACE_H

#include "Consola.h"
#include "Ponto.h"
#include "vector"
#include "Mundo.h"

using namespace std;

class Interface {
    vector<Mundo> mundos;
    fstream file;
    int estado;
    vector<Mundo>::iterator iterador;
public:
    Interface();
    Interface(const Interface& outro) = delete;
    Interface& operator=(const Interface& outro) = delete;
    void inicia();
    void initial_screen();
    void screen_config_stage();
    void printborders(int lim);
    void printcaracter(Ponto aux, int i, int car, int lim);
    string getlinha();
    void mostrainfo(string aux);
    void clrscreen();
private:

};

#endif /* INTERFACE_H */

