#ifndef FSUPERMAN_H
#define FSUPERMAN_H

#include "Formiga.h"

class FSuperman : public Formiga{
public:
    FSuperman(int linha, int coluna, int id, Ninho* ninho_a_que_pertence);
    void consomeEnergia(int mov_efetivo) override;
    Formiga* duplica() const override;
    char getTipo() const override;
    float percentage_takes_from_migalha() const override;
    bool ckif_is_to_move_to_ninho() const override;
private:

};

#endif /* FSUPERMAN_H */

