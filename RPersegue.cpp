#include "RPersegue.h"
#include "Comunidade.h"
#include "Mundo.h"
#include "Formiga.h"

RPersegue::RPersegue() {}

bool RPersegue::condicao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    return mundo->ckif_formigas_no_raio(comunidade, formiga->getRaioVisao(), formiga->getPonto());
}

void RPersegue::accao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    Ponto aux = mundo->local_formiga_enemy(formiga->getRaioVisao(), formiga->getPonto(), comunidade);
    if(aux.getX() == -1)
        return;
    int i, j;
    if(aux.getX() == formiga->getPonto().getX()){
        for(i=1;(abs(aux.getY()-formiga->getPonto().getY())-i) > 0;i++){
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
        for(i=1;(abs(aux.getX()-formiga->getPonto().getX())-i) > 0;i++){
            if(aux.getX() > formiga->getPonto().getX()){
                if(formiga->moveFormiga((aux.getX()-formiga->getPonto().getX())-i, 0, mundo))
                    return;
                if(formiga->moveFormiga((aux.getX()-formiga->getPonto().getX())+i, 0, mundo))
                    return;
            }
        }
    }    
    if(abs(aux.getX()-formiga->getPonto().getX()) >= abs(aux.getY()-formiga->getPonto().getY())){
        i=1;
        j=0;
    }else{
        i=0;
        j=1;
    }
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

Regra* RPersegue::duplica() const {return new RPersegue(*this);}

