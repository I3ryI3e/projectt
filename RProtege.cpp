#include "RProtege.h"
#include "Mundo.h"
#include "Formiga.h"

RProtege::RProtege() {}

bool RProtege::condicao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    if((mundo->ckif_formigas_no_raio(comunidade,formiga->getRaioVisao(),formiga->getPonto())) && (comunidade->ckif_formiga_da_mesma_comunidade_num_raio_visao(formiga->getPonto(),formiga->getRaioVisao())))
        return true;
    return false;
}

void RProtege::accao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    int ponto_central_x, ponto_central_y;
    Ponto enemy(mundo->local_formiga_enemy(formiga->getRaioVisao(),formiga->getPonto(),comunidade));
    if(enemy.getX() == -1)
        return;
    Ponto ally(comunidade->local_formiga_a_proteger(formiga->getRaioVisao(),formiga->getPonto()));
    if(ally.getX() == -1)
        return;
    ponto_central_x = (enemy.getX()+ally.getX())/2;
    ponto_central_y = (enemy.getY()+ally.getY())/2;
    if(formiga->moveFormiga(ponto_central_x-formiga->getPonto().getX(),ponto_central_y-formiga->getPonto().getY(),mundo))
        return;
    Ponto aux(ponto_central_x, ponto_central_y);
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

Regra* RProtege::duplica() const {return new RProtege(*this);}




