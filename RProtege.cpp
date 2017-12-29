#include "RProtege.h"

RProtege::RProtege() {
}

bool RProtege::condicao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {

}

void RProtege::accao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {

}

Regra* RProtege::duplica() const {
    return new RProtege(*this);
}




