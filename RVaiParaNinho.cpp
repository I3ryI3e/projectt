#include "RVaiParaNinho.h"
#include "Formiga.h"
#include "Comunidade.h"

RVaiParaNinho::RVaiParaNinho() {
}

bool RVaiParaNinho::condicao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    if(formiga->ckif_is_to_move_to_ninho() && (formiga->getNIteracoesSemNinho()>=10) && formiga->ckif_ninho_in_raio_visao())
        return true;
    return false;
}

void RVaiParaNinho::accao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    if(formiga->moveFormiga(comunidade->getNinhoPonto().getX()-formiga->getPonto().getX(),comunidade->getNinhoPonto().getY()-formiga->getPonto().getY(),mundo)){
        formiga->resetNIteracoesSemNinho();
        return;
    }
    Ponto aux(comunidade->getNinhoPonto().getX(), comunidade->getNinhoPonto().getY());
    int i, j;
    if(aux.getX() == formiga->getPonto().getX()){
        for(i=1;(abs(aux.getY()-formiga->getPonto().getY())-i) > 0;i++){
            if(aux.getY() > formiga->getPonto().getY()){
                if(formiga->moveFormiga(0, (aux.getY()-formiga->getPonto().getY())-i, mundo)){
                    formiga->resetNIteracoesSemNinho();
                    return;
                }
            }else{
                if(formiga->moveFormiga(0, (aux.getY()-formiga->getPonto().getY())+i, mundo)){
                    formiga->resetNIteracoesSemNinho();
                    return;
                }
            }
        }
    }
    if(aux.getY() == formiga->getPonto().getY()){
        for(i=1;(abs(aux.getX()-formiga->getPonto().getX())-i) > 0;i++){
            if(aux.getX() > formiga->getPonto().getX()){
                if(formiga->moveFormiga((aux.getX()-formiga->getPonto().getX())-i, 0, mundo)){
                    formiga->resetNIteracoesSemNinho();
                    return;
                }
                if(formiga->moveFormiga((aux.getX()-formiga->getPonto().getX())+i, 0, mundo)){
                    formiga->resetNIteracoesSemNinho();
                    return;
                }
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
                if(formiga->moveFormiga((aux.getX()-formiga->getPonto().getX())-i, (aux.getY()-formiga->getPonto().getY())-j, mundo)){
                    formiga->resetNIteracoesSemNinho();
                    return;
                }
            }else{
                if(formiga->moveFormiga((aux.getX()-formiga->getPonto().getX())-i, (aux.getY()-formiga->getPonto().getY())+j, mundo)){
                    formiga->resetNIteracoesSemNinho();
                    return;
                }
            }
        else
            if(aux.getY() > formiga->getPonto().getY()){
                if(formiga->moveFormiga((aux.getX()-formiga->getPonto().getX())+i, (aux.getY()-formiga->getPonto().getY())-j, mundo)){
                    formiga->resetNIteracoesSemNinho();
                    return;
                }
            }else{
                if(formiga->moveFormiga((aux.getX()-formiga->getPonto().getX())+i, (aux.getY()-formiga->getPonto().getY())+j, mundo)){
                    formiga->resetNIteracoesSemNinho();
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


Regra* RVaiParaNinho::duplica() const {
    return new RVaiParaNinho(*this);
}
