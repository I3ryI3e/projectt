/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FExploradora.cpp
 * Author: I3ryI3e
 * 
 * Created on 21 de Dezembro de 2017, 18:21
 */

#include "FExploradora.h"
#include "RPasseia.h"

FExploradora::FExploradora(int linha, int coluna, int id, Ninho* ninho_a_que_pertence): Formiga(linha,coluna,200,id,200,10,8,ninho_a_que_pertence) {
   addRegra(new RPasseia);
}

void FExploradora::iteracao(Mundo* mundo_atual, Comunidade* comunidade) {
    Formiga::iteracao(mundo_atual, 0);
}

FExploradora::~FExploradora() {

}



