#ifndef FASSALTANTE_H
#define FASSALTANTE_H
#include "Formiga.h"

class FAssaltante : public Formiga {
public:
    FAssaltante(int linha, int coluna, int id, Ninho* ninho_a_que_pertence);
    void iteracao(Mundo* mundo_atual, Comunidade* comunidade) override;
    virtual ~FAssaltante();

private:

};

#endif /* FASSALTANTE_H */

