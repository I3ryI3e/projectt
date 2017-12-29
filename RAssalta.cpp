#include "RAssalta.h"
#include "Mundo.h"
#include "Formiga.h"

RAssalta::RAssalta() {
}

bool RAssalta::condicao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
}

void RAssalta::accao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {

}

Regra* RAssalta::duplica() const {
    return new RAssalta(*this);
}






