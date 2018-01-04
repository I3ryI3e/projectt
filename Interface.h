#ifndef INTERFACE_H
#define INTERFACE_H

#include "Consola.h"
#include "Ponto.h"

using namespace std;

class Interface {
public:
    Interface() = delete;
    static void initial_screen();
    static void screen_config_stage();
    static void printborders(int lim, Ponto foca);
    static void printcaracter(Ponto aux, int i, int car, int lim);
    static string getlinha();
    static void mostrainfo(string aux);
    static void clrscreen();
private:

};

#endif /* INTERFACE_H */

