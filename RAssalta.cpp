#include "RAssalta.h"
#include "Mundo.h"
#include "Formiga.h"

RAssalta::RAssalta() {
}

bool RAssalta::condicao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    return mundo->ckif_formigas_no_raio(comunidade, formiga->getRaioMovimento(), formiga->getPonto());
}

void RAssalta::accao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    Ponto aux = mundo->local_formiga_enemy(formiga->getRaioMovimento(), formiga->getPonto(), comunidade);
    int i, j;
    float auxf;
    if(aux.getX() == formiga->getPonto().getX()){
        for(i=1;(abs(aux.getY()-formiga->getPonto().getY())-i) > 0;i++){
            if(aux.getY() > formiga->getPonto().getY()){
                if(formiga->moveFormiga(0, (aux.getY()-formiga->getPonto().getY())-i, mundo))
                    if((auxf = mundo->try_to_get_energy_from_formiga(aux)) != -1){
                        formiga->modifica_energia(auxf);
                        return;
                    }
            }else{
                if(formiga->moveFormiga(0, (aux.getY()-formiga->getPonto().getY())+i, mundo))
                    if((auxf = mundo->try_to_get_energy_from_formiga(aux)) != -1){
                        formiga->modifica_energia(auxf);
                        return;
                    }
            }
        }
    }
    if(aux.getY() == formiga->getPonto().getY()){
        for(i=1;(abs(aux.getX()-formiga->getPonto().getX())-i) > 0;i++){
            if(aux.getX() > formiga->getPonto().getX()){
                if(formiga->moveFormiga((aux.getX()-formiga->getPonto().getX())-i, 0, mundo))
                    if((auxf = mundo->try_to_get_energy_from_formiga(aux)) != -1){
                        formiga->modifica_energia(auxf);
                        return;
                    }
                if(formiga->moveFormiga((aux.getX()-formiga->getPonto().getX())+i, 0, mundo))
                    if((auxf = mundo->try_to_get_energy_from_formiga(aux)) != -1){
                        formiga->modifica_energia(auxf);
                        return;
                    }
            }
        }
    }    
    i = j = 1;
    do{
        if(aux.getX() > formiga->getPonto().getX())
            if(aux.getY() > formiga->getPonto().getY()){
                if(formiga->moveFormiga((aux.getX()-formiga->getPonto().getX())-i, (aux.getY()-formiga->getPonto().getY())-j, mundo))
                    if((auxf = mundo->try_to_get_energy_from_formiga(aux)) != -1){
                        formiga->modifica_energia(auxf);
                        return;
                    }
            }else{
                if(formiga->moveFormiga((aux.getX()-formiga->getPonto().getX())-i, (aux.getY()-formiga->getPonto().getY())+j, mundo))
                    if((auxf = mundo->try_to_get_energy_from_formiga(aux)) != -1){
                        formiga->modifica_energia(auxf);
                        return;
                    }
            }
        else
            if(aux.getY() > formiga->getPonto().getY()){
                if(formiga->moveFormiga((aux.getX()-formiga->getPonto().getX())+i, (aux.getY()-formiga->getPonto().getY())-j, mundo))
                    if((auxf = mundo->try_to_get_energy_from_formiga(aux)) != -1){
                        formiga->modifica_energia(auxf);
                        return;
                    }
            }else{
                if(formiga->moveFormiga((aux.getX()-formiga->getPonto().getX())+i, (aux.getY()-formiga->getPonto().getY())+j, mundo))
                    if((auxf = mundo->try_to_get_energy_from_formiga(aux)) != -1){
                        formiga->modifica_energia(auxf);
                        return;
                    }
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

Regra* RAssalta::duplica() const {
    return new RAssalta(*this);
}






