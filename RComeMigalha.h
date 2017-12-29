
#ifndef RCOMEMIGALHA_H
#define RCOMEMIGALHA_H
#include "Regra.h"

class RComeMigalha : public Regra {
public:
    RComeMigalha();
    bool condicao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) override;
    void accao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) override;
    Regra* duplica() const override;

private:

};

#endif /* RCOMEMIGALHA_H */

