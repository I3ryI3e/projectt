#ifndef RSUPERMAN_H
#define RSUPERMAN_H

#include "Regra.h"

class RSuperman : public Regra{
public:
    RSuperman();
    bool condicao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) override;
    void accao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) override;
    Regra* duplica() const override;
private:

};

#endif /* RSUPERMAN_H */

