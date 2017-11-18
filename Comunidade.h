#ifndef COMUNIDADE_H
#define COMUNIDADE_H

#include <vector>
using namespace std;
#include "Ninho.h"
class Formiga;

class Comunidade {
    Ninho ninho;
    vector <Formiga*> formigueiro;
public:
    Comunidade();
    Comunidade(const Comunidade& orig);
    virtual ~Comunidade();
private:

};

#endif /* COMUNIDADE_H */

