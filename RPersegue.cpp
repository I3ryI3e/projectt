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
    }else{
        return;
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
    }else{
        return;
    }
    
    i = j = 1;
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
    }while(((abs(aux.getX()-formiga->getPonto().getX())-i) > 0) && ((abs(aux.getY()-formiga->getPonto().getY()))-j > 0));
        
//    if(abs(formiga->getPonto().getX()-aux.getX()) <= formiga->getRaioMovimento() && abs(formiga->getPonto().getY()-aux.getY()) <= formiga->getRaioMovimento())
//        if(formiga->moveFormiga((aux.getX()-formiga->getPonto().getX())-1,(aux.getY()-formiga->getPonto().getY()-1),mundo)){
//            return;
//        }
//    for(int i=1;i<=(formiga->getRaioVisao()-formiga->getRaioMovimento());i++){
//        if((abs(formiga->getPonto().getX()-aux.getX())-i) <= formiga->getRaioMovimento() && (abs(formiga->getPonto().getY()-aux.getY())-i) <= formiga->getRaioMovimento()){
//            if(formiga->moveFormiga(((aux.getX()-formiga->getPonto().getX())-i),((aux.getY()-formiga->getPonto().getY())-i),mundo))
//                return;
//        }
//    }
}

Regra* RPersegue::duplica() const {
    return new RPersegue(*this);
}

