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
    if(abs(formiga->getPonto().getX()-aux.getX()) <= formiga->getRaioMovimento() && abs(formiga->getPonto().getY()-aux.getY()) <= formiga->getRaioMovimento())
        if(formiga->moveFormiga((aux.getX()-formiga->getPonto().getX())-1,(aux.getY()-formiga->getPonto().getY()-1),mundo)){
            return;
        }
    for(int i=1;i<=(formiga->getRaioVisao()-formiga->getRaioMovimento());i++){
        if((abs(formiga->getPonto().getX()-aux.getX())-i) <= formiga->getRaioMovimento() && (abs(formiga->getPonto().getY()-aux.getY())-i) <= formiga->getRaioMovimento()){
            if(formiga->moveFormiga(((aux.getX()-formiga->getPonto().getX())-i),((aux.getY()-formiga->getPonto().getY())-i),mundo))
                return;
        }
    }
}


