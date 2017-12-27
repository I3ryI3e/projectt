#ifndef RVAIPARANINHO_H
#define RVAIPARANINHO_H
#include "Regra.h"

class RVaiParaNinho : public Regra{
public:
    RVaiParaNinho();
    bool condicao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) override;
    void accao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) override;

private:

};

#endif /* RVAIPARANINHO_H */

