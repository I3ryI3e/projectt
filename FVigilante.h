#ifndef FVIGILANTE_H
#define FVIGILANTE_H
#include "Formiga.h"

class FVigilante : public Formiga {
public:
    FVigilante(int linha, int coluna, int id, Ninho* ninho_a_que_pertence);
    void iteracao(Mundo* mundo_atual, Comunidade* comunidade) override;
    virtual ~FVigilante();

private:

};

#endif /* FVIGILANTE_H */

