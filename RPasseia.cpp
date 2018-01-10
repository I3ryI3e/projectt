#include "RPasseia.h"
#include "Formiga.h"
#include <cstdlib>
#include <random>
#include <chrono>

RPasseia::RPasseia() {}

void RPasseia::accao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    int mov,auxx,auxy,x,y;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator (seed);
    uniform_int_distribution<int> distmov(0,formiga->getRaioMovimento());
    uniform_int_distribution<int> distquad(0,3);
    do{
        mov = distquad(generator);
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

Regra* RPasseia::duplica() const {return new RPasseia(*this);}
