#include "RProtege.h"
#include "Mundo.h"
#include "Formiga.h"

RProtege::RProtege() {
}

bool RProtege::condicao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    if((mundo->ckif_formigas_no_raio_visao(comunidade,formiga->getRaioVisao(),formiga->getPonto())) && (comunidade->ckif_formiga_da_mesma_comunidade_num_raio_visao(formiga->getPonto(),formiga->getRaioVisao(),formiga)))
        return true;
    return false;
}

void RProtege::accao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    int ponto_central_x, ponto_central_y;
    Ponto enemy = mundo->local_formiga_enemy(formiga->getRaioVisao(),formiga->getPonto(),comunidade);
    Ponto ally = comunidade->local_formiga_a_proteger(formiga->getRaioVisao(),formiga->getPonto(),formiga);
    ponto_central_x = (enemy.getX()+ally.getX())/2;
    ponto_central_y = (enemy.getY()+ally.getY())/2;
    if(abs(ponto_central_x-formiga->getPonto().getX())<=formiga->getRaioMovimento() && abs(ponto_central_y-formiga->getPonto().getY())<=formiga->getRaioMovimento()){
        if(formiga->moveFormiga(ponto_central_x-formiga->getPonto().getX(),ponto_central_y-formiga->getPonto().getY(),mundo))
            return;
        else{
            
        }
    }
}

Regra* RProtege::duplica() const {
    return new RProtege(*this);
}




