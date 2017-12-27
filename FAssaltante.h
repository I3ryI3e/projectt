#ifndef FASSALTANTE_H
#define FASSALTANTE_H
#include "Formiga.h"

class FAssaltante : public Formiga {
public:
    FAssaltante(int linha, int coluna, int id, Ninho* ninho_a_que_pertence);
    void consomeEnergia(int mov_efetivo) override;
    virtual ~FAssaltante();

private:

};

#endif /* FASSALTANTE_H */

