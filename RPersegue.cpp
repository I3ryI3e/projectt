#include "RPersegue.h"
#include "Comunidade.h"
#include "Mundo.h"
#include "Formiga.h"

RPersegue::RPersegue() {
}

bool RPersegue::condicao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    return mundo->ckif_formigas_no_raio_visao(comunidade, formiga->getRaioVisao(), formiga->getPonto());
}

void RPersegue::accao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    Ponto aux = comunidade->local_formiga_com_mais_energia(formiga->getRaioVisao(),formiga->getPonto());
    
}

Regra* RPersegue::duplica() const {
    return new RPersegue(*this);
}

