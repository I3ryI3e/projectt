#ifndef RASSALTA_H
#define RASSALTA_H
#include "Regra.h"

class RAssalta : public Regra {
public:
    RAssalta();
    bool condicao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) override;
    void accao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) override;
    Regra* duplica() const override;


private:

};

#endif /* RASSALTA_H */

