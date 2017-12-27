#include "RPasseia.h"
#include "Formiga.h"
#include <cstdlib>


RPasseia::RPasseia() {
}

void RPasseia::accao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    int mov,auxx,auxy,x,y;
    srand (time(NULL));
    do{
            mov = rand() % 4;
            auxx= (rand() % formiga->getRaioMovimento())+1;
            auxy= (rand() % formiga->getRaioMovimento())+1;
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

