#ifndef FVIGILANTE_H
#define FVIGILANTE_H
#include "Formiga.h"

class FVigilante : public Formiga {
public:
    FVigilante(int linha, int coluna, int id, Ninho* ninho_a_que_pertence);
    void consomeEnergia(int mov_efetivo) override;
    Formiga* duplica() const override;
    float percentage_takes_from_migalha() const override;
    char getTipo() const override;
    bool ckif_is_to_move_to_ninho() const override;
    virtual ~FVigilante();

private:

};

#endif /* FVIGILANTE_H */

