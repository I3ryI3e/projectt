#ifndef COMUNIDADE_H
#define COMUNIDADE_H

#include <vector>

#include "Formiga.h"
#include "Ninho.h"

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

