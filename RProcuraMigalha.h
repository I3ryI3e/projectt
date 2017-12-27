#ifndef RPROCURAMIGALHA_H
#define RPROCURAMIGALHA_H
#include "Regra.h"

class RProcuraMigalha : public Regra{
public:
    RProcuraMigalha();
    bool condicao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) override;
    void accao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) override;

private:

};

#endif /* RPROCURAMIGALHA_H */

