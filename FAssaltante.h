#ifndef FASSALTANTE_H
#define FASSALTANTE_H
#include "Formiga.h"

class FAssaltante : public Formiga {
public:
    FAssaltante(int linha, int coluna, int id, Ninho* ninho_a_que_pertence);
    void consomeEnergia(int mov_efetivo) override;
    float percentage_takes_from_migalha() const override;
    Formiga* duplica() const override;
    char getTipo() const override;
    bool ckif_is_to_move_to_ninho() const override;
    virtual ~FAssaltante();

private:

};

#endif /* FASSALTANTE_H */

