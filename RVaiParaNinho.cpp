#include "RVaiParaNinho.h"

RVaiParaNinho::RVaiParaNinho() {
}

bool RVaiParaNinho::condicao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    
}

void RVaiParaNinho::accao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {

}

Regra* RVaiParaNinho::duplica() const {
    return new RVaiParaNinho(*this);
}
