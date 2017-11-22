#ifndef MIGALHA_H
#define MIGALHA_H

#include "Ponto.h"

class Migalha {
    Ponto local_m;
    int energia_m;
public:
    Migalha(int linha, int coluna);
    Ponto getPonto() const;
    virtual ~Migalha();
private:

};

#endif /* MIGALHA_H */

