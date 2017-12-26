/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FCuidadora.h
 * Author: I3ryI3e
 *
 * Created on 21 de Dezembro de 2017, 18:20
 */

#ifndef FCUIDADORA_H
#define FCUIDADORA_H
#include "Formiga.h"

class FCuidadora : public Formiga {
public:
    FCuidadora(int linha, int coluna, int id, Ninho* ninho_a_que_pertence);
    void iteracao(Mundo* mundo_atual, Comunidade* comunidade) override;
    virtual ~FCuidadora();
private:

};

#endif /* FCUIDADORA_H */

