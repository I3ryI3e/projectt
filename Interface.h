#ifndef INTERFACE_H
#define INTERFACE_H

#include "Consola.h"
#include "Ponto.h"

using namespace std;

class Interface {
public:
    Interface() = delete;
    static void setconfig_screen();
    static void printborders(int lim);
    static void printcaracter(Ponto aux, int i, int car, int lim);
    static string getlinha();
private:

};

#endif /* INTERFACE_H */

