#ifndef FCUIDADORA_H
#define FCUIDADORA_H
#include "Formiga.h"

class FCuidadora : public Formiga {
public:
    FCuidadora(int linha, int coluna, int id, Ninho* ninho_a_que_pertence);
    void iteracao(Mundo* mundo_atual, Comunidade* comunidade) override;
    virtual ~FCuidadora();
private:

};

#endif /* FCUIDADORA_H */

