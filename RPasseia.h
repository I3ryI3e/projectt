/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RPasseia.h
 * Author: I3ryI3e
 *
 * Created on 22 de Dezembro de 2017, 18:03
 */

#ifndef RPASSEIA_H
#define RPASSEIA_H
#include "Regra.h"

class RPasseia : public Regra {
public:
    RPasseia();
    bool condicao() override;
    void accao(Formiga* formiga) override;
   



private:

};

#endif /* RPASSEIA_H */

