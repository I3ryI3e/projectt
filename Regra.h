#ifndef REGRA_H
#define REGRA_H
class Formiga;
class Mundo;
class Comunidade;
#include <ctime>

class Regra {
public:
    Regra();
    virtual bool condicao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade);
    virtual void accao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) = 0;
    virtual ~Regra();
private:

};

#endif /* REGRA_H */

