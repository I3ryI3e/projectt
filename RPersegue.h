#ifndef RPERSEGUE_H
#define RPERSEGUE_H
#include "Regra.h"

class RPersegue : public Regra {
public:
    RPersegue();
    bool condicao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) override;
    void accao(Formiga* formiga, Mundo* mundo) override;
  

private:

};

#endif /* RPERSEGUE_H */

