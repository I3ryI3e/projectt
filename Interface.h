#ifndef INTERFACE_H
#define INTERFACE_H

#include "Consola.h"
#include "Ponto.h"
#include "vector"
#include "Mundo.h"
#include <fstream>
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
    void guarda_muda_apaga(string linha);
    void initial_screen();
    void screen_config_stage();
    void printborders(int lim, Ponto foca);
    void printcaracter(Ponto aux, int i, int car, int lim);
    string getlinha();
    void mostrainfo(string aux);
    void clrscreen();
    void gotox0y0();
private:
};

#endif /* INTERFACE_H */

