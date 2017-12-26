/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RFoge.h
 * Author: I3ryI3e
 *
 * Created on 22 de Dezembro de 2017, 18:02
 */

#ifndef RFOGE_H
#define RFOGE_H
#include "Regra.h"

class RFoge : public Regra {
public:
    RFoge();
    bool condicao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade) override;
    void accao(Formiga* formiga, Mundo* mundo) override;

private:

};

#endif /* RFOGE_H */

