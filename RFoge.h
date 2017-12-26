#ifndef RFOGE_H
#define RFOGE_H
#include "Regra.h"

class RFoge : public Regra {
public:
    RFoge();
    bool condicao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) override;
    void accao(Formiga* formiga, Mundo* mundo) override;

private:

};

#endif /* RFOGE_H */

