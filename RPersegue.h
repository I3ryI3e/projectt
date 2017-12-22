/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RPersegue.h
 * Author: I3ryI3e
 *
 * Created on 22 de Dezembro de 2017, 18:02
 */

#ifndef RPERSEGUE_H
#define RPERSEGUE_H
#include "Regra.h"

class RPersegue : public Regra {
public:
    RPersegue();
    bool condicao() override;
    void accao(Formiga* formiga) override;
  

private:

};

#endif /* RPERSEGUE_H */

