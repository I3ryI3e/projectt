#ifndef FCUIDADORA_H
#define FCUIDADORA_H
#include "Formiga.h"

class FCuidadora : public Formiga {
public:
    FCuidadora(int linha, int coluna, int id, Ninho* ninho_a_que_pertence);
    void consomeEnergia(int mov_efetivo) override;
    Formiga* duplica() const override;
    float percentage_takes_from_migalha() const override;
    virtual ~FCuidadora();
private:

};

#endif /* FCUIDADORA_H */

