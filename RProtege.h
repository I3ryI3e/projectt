#ifndef RPROTEGE_H
#define RPROTEGE_H
#include "Regra.h"

class RProtege :public Regra{
public:
    RProtege();
    bool condicao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) override;
    void accao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) override;
    Regra* duplica() const override;

    


private:

};

#endif /* RPROTEGE_H */

