/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RProtege.h
 * Author: I3ryI3e
 *
 * Created on 22 de Dezembro de 2017, 18:02
 */

#ifndef RPROTEGE_H
#define RPROTEGE_H
#include "Regra.h"

class RProtege :public Regra{
public:
    RProtege();
    bool condicao(Formiga* formiga, Mundo* mundo) override;
    void accao(Formiga* formiga, Mundo* mundo) override;
    


private:

};

#endif /* RPROTEGE_H */

