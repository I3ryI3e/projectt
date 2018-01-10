#include "RFoge.h"
#include "Mundo.h"
#include "Formiga.h"
#include <chrono>
#include <random>

RFoge::RFoge() {}

bool RFoge::condicao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    return mundo->ckif_formigas_no_raio(comunidade, formiga->getRaioVisao(), formiga->getPonto());
}

void RFoge::accao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    int mov,auxx,auxy,x,y;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator (seed);
    uniform_int_distribution<int> distmov(0,formiga->getRaioMovimento());
    mov = mundo->best_quadrante_to_runaway(comunidade,formiga->getRaioVisao(),formiga->getPonto());
    do{
        auxx= distmov(generator);
        auxy= distmov(generator);
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

Regra* RFoge::duplica() const {return new RFoge(*this);}


