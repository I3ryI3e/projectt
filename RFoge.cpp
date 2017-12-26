/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RFoge.cpp
 * Author: I3ryI3e
 * 
 * Created on 22 de Dezembro de 2017, 18:02
 */

#include "RFoge.h"
#include "Mundo.h"
#include "Formiga.h"

RFoge::RFoge() {
}

bool RFoge::condicao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) {
    return mundo->ckif_formigas_no_raio_visao(comunidade, formiga->getRaioVisao(), formiga->getPonto());
}

void RFoge::accao(Formiga* formiga, Mundo* mundo) {

}


