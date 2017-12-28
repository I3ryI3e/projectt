#ifndef FEXPLORADORA_H
#define FEXPLORADORA_H
#include "Formiga.h"

class FExploradora : public Formiga{
public:
    FExploradora(int linha, int coluna, int id, Ninho* ninho_a_que_pertence);
    void consomeEnergia(int mov_efetivo) override;
    int percentage_takes_from_migalha() const override;



private:

};

#endif /* FEXPLORADORA_H */

