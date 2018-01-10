#include "RSuperman.h"
#include "Comunidade.h"
#include "Formiga.h"
#include "Mundo.h"

RSuperman::RSuperman() {
}

bool RSuperman::condicao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    if(formiga->getNIteracoesSemNinho()>=7)
        return true;
    return false;
}

void RSuperman::accao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    Ponto aux = comunidade->local_formiga_mesma_comunidade_com_menos_energia(formiga->getPonto());
    if(aux.getX() == -1)
        return;
    float energia;
    for(int i=-1;i<2;i++){
        for(int j=-1;j<2;j++){
            if(mundo->mckif_noants_nonest(aux.getX()+i, aux.getY()+j)){
                if(formiga->mov_SuperFormiga(aux.getX()+i, aux.getY()+j, mundo)){
                    comunidade->addenergFormiga(aux.getX(), aux.getY(), (formiga->getenergia()*0.75));
                    formiga->modifica_energia(-(formiga->getenergia()*0.75));
                    formiga->resetNIteracoesSemNinho();
                    return;
                }
            }
        }
    }
}

Regra* RSuperman::duplica() const {return new RSuperman(*this);}
