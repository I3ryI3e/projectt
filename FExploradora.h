#ifndef FEXPLORADORA_H
#define FEXPLORADORA_H

#include "Formiga.h"

class FExploradora : public Formiga{
public:
    FExploradora(int linha, int coluna, int id, Ninho* ninho_a_que_pertence);
    void consomeEnergia(int mov_efetivo) override;
    Formiga* duplica() const override;
    float percentage_takes_from_migalha() const override;
    bool ckif_is_to_move_to_ninho() const override;
    char getTipo() const override;
private:
};

#endif /* FEXPLORADORA_H */

