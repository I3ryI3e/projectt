#include "RFoge.h"
#include "Mundo.h"
#include "Formiga.h"

RFoge::RFoge() {
}

bool RFoge::condicao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    return mundo->ckif_formigas_no_raio_visao(comunidade, formiga->getRaioVisao(), formiga->getPonto());
}

void RFoge::accao(Formiga* formiga, Mundo* mundo) {

}


