#include "RProcuraMigalha.h"
#include "Mundo.h"
#include "Formiga.h"

RProcuraMigalha::RProcuraMigalha() {
}

bool RProcuraMigalha::condicao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    return mundo->ckif_migalhas_no_raio_visao(formiga->getRaioVisao(),formiga->getPonto());
}

void RProcuraMigalha::accao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    Ponto aux = mundo->local_migalha_com_mais_energia(formiga->getRaioVisao(),formiga->getPonto());
    if(abs(formiga->getPonto().getX()-aux.getX()) <= formiga->getRaioMovimento() && abs(formiga->getPonto().getY()-aux.getY()) <= formiga->getRaioMovimento())
        if(formiga->moveFormiga((aux.getX()-formiga->getPonto().getX()),(aux.getY()-formiga->getPonto().getY()),mundo)){
            return;
        }
    for(int i=1;i<=(formiga->getRaioVisao()-formiga->getRaioMovimento());i++){
        if((abs(formiga->getPonto().getX()-aux.getX())-i) <= formiga->getRaioMovimento() && (abs(formiga->getPonto().getY()-aux.getY())-i) <= formiga->getRaioMovimento()){
            if(formiga->moveFormiga(((aux.getX()-formiga->getPonto().getX())-i),((aux.getY()-formiga->getPonto().getY())-i),mundo))
                return;
        }
    }
}

Regra* RProcuraMigalha::duplica() const {
    return new RProcuraMigalha(*this);
}

