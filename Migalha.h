#ifndef MIGALHA_H
#define MIGALHA_H

#include "Ponto.h"

class Migalha {
    Ponto local_m;
    int energia_m;
public:
    Migalha();
    Migalha(const Migalha& orig);
    virtual ~Migalha();
private:

};

#endif /* MIGALHA_H */

