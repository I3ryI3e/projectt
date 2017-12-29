#ifndef RPASSEIA_H
#define RPASSEIA_H
#include "Regra.h"

class RPasseia : public Regra {
public:
    RPasseia();
    void accao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) override;
    Regra* duplica() const override;

private:

};

#endif /* RPASSEIA_H */

