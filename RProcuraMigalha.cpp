#include "RProcuraMigalha.h"
#include "Mundo.h"
#include "Formiga.h"

RProcuraMigalha::RProcuraMigalha() {}

bool RProcuraMigalha::condicao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    return mundo->ckif_migalhas_no_raio_visao(formiga->getRaioVisao(),formiga->getPonto());
}

void RProcuraMigalha::accao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    Ponto aux = mundo->local_migalha_com_mais_energia(formiga->getRaioVisao(),formiga->getPonto());
    int i, j;
    if(aux.getX() == formiga->getPonto().getX()){
        for(i=0;(abs(aux.getY()-formiga->getPonto().getY())-i) > 0;i++){
            if(aux.getY() > formiga->getPonto().getY()){
                if(formiga->moveFormiga(0, (aux.getY()-formiga->getPonto().getY())-i, mundo))
                    return;
            }else{
                if(formiga->moveFormiga(0, (aux.getY()-formiga->getPonto().getY())+i, mundo))
                    return;
            }
        }
    }
    if(aux.getY() == formiga->getPonto().getY()){
        for(i=0;(abs(aux.getX()-formiga->getPonto().getX())-i) > 0;i++){
            if(aux.getX() > formiga->getPonto().getX()){
                if(formiga->moveFormiga((aux.getX()-formiga->getPonto().getX())-i, 0, mundo))
                    return;
                if(formiga->moveFormiga((aux.getX()-formiga->getPonto().getX())+i, 0, mundo))
                    return;
            }
        }
    }
    i = j = 0;
    do{
        if(aux.getX() > formiga->getPonto().getX())
            if(aux.getY() > formiga->getPonto().getY()){
                if(formiga->moveFormiga((aux.getX()-formiga->getPonto().getX())-i, (aux.getY()-formiga->getPonto().getY())-j, mundo))
                    return;
            }else{
                if(formiga->moveFormiga((aux.getX()-formiga->getPonto().getX())-i, (aux.getY()-formiga->getPonto().getY())+j, mundo))
                    return;
            }
        else
            if(aux.getY() > formiga->getPonto().getY()){
                if(formiga->moveFormiga((aux.getX()-formiga->getPonto().getX())+i, (aux.getY()-formiga->getPonto().getY())-j, mundo))
                    return;
            }else{
                if(formiga->moveFormiga((aux.getX()-formiga->getPonto().getX())+i, (aux.getY()-formiga->getPonto().getY())+j, mundo))
                    return;
            }
        
        if(abs((aux.getX()-formiga->getPonto().getX())-i) == 0){
            ++j;            
        }else{
            if(abs((aux.getY()-formiga->getPonto().getY())-j) == 0){
                ++i;
            }else{
                if(i==j)
                    ++i;
                else
                    ++j;
            }
        }
    }while(((abs(aux.getX()-formiga->getPonto().getX())-i) > 0) || ((abs(aux.getY()-formiga->getPonto().getY()))-j > 0));
}

Regra* RProcuraMigalha::duplica() const {return new RProcuraMigalha(*this);}

