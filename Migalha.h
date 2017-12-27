#ifndef MIGALHA_H
#define MIGALHA_H

#include "Ponto.h"

class Migalha {
    Ponto local_m;
    int energia_m, energia_inicial;
public:
    Migalha(int linha, int coluna, int energini);
    Ponto getPonto() const;
    string getInfo()const;
    int getEnergia()const;
    void iteracao();
    virtual ~Migalha();
private:

};

#endif /* MIGALHA_H */

