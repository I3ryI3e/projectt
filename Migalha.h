#ifndef MIGALHA_H
#define MIGALHA_H

#include "Ponto.h"

class Migalha {
    Ponto local_m;
    float energia_m, energia_inicial;
public:
    Migalha(int linha, int coluna, float energini);
    Ponto getPonto() const;
    string getInfo()const;
    float getEnergia()const;
    float loseEnergy(float percentage_of_energy_to_take);
    void iteracao();
    virtual ~Migalha();
private:

};

#endif /* MIGALHA_H */

