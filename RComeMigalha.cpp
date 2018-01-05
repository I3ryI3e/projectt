#include "RComeMigalha.h"
#include "Mundo.h"
#include "Formiga.h"

RComeMigalha::RComeMigalha() {}

bool RComeMigalha::condicao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    return mundo->ckif_migalha_adjacente(formiga->getPonto());
}

void RComeMigalha::accao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    Ponto aux = mundo->local_migalha_com_mais_energia(1,formiga->getPonto());
    float valor_ganho = mundo->try_to_get_energy_from_migalha(aux,formiga->percentage_takes_from_migalha());
    formiga->modifica_energia(valor_ganho);
}

Regra* RComeMigalha::duplica() const {return new RComeMigalha(*this);}




