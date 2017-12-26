#ifndef FEXPLORADORA_H
#define FEXPLORADORA_H
#include "Formiga.h"

class FExploradora : public Formiga{
public:
    FExploradora(int linha, int coluna, int id, Ninho* ninho_a_que_pertence);
    void iteracao(Mundo* mundo_atual, Comunidade* comunidade) override;
    virtual ~FExploradora();


private:

};

#endif /* FEXPLORADORA_H */

