#include "RFoge.h"
#include "Mundo.h"
#include "Formiga.h"

RFoge::RFoge() {
}

bool RFoge::condicao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    return mundo->ckif_formigas_no_raio(comunidade, formiga->getRaioVisao(), formiga->getPonto());
}

void RFoge::accao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    int mov,auxx,auxy,x,y;
    srand (time(NULL));
    mov = mundo->best_quadrante_to_runaway(comunidade,formiga->getRaioVisao(),formiga->getPonto());
    do{
        auxx= (rand() % (formiga->getRaioMovimento())+1);
        auxy= (rand() % (formiga->getRaioMovimento())+1);
        switch(mov){
            case 0:
                x= auxx;
                y= auxy;
                break;
            case 1:
                x= -auxx;
                y=  auxy;
                break;
            case 2:
                x= -auxx;
                y= -auxy;
                break;
            case 3:
                x= auxx;
                y= -auxy;
                break;
        }
    }while(!formiga->moveFormiga(x,y,mundo));
}

Regra* RFoge::duplica() const {
    return new RFoge(*this);
}


