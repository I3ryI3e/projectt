#ifndef INTERFACE_H
#define INTERFACE_H

#include "Consola.h"

using namespace std;

class Interface {
public:
    Interface();
    void setconfig_screen();
    Interface(const Interface& orig);
    virtual ~Interface();
private:

};

#endif /* INTERFACE_H */

