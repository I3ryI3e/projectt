/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RAssalta.h
 * Author: I3ryI3e
 *
 * Created on 22 de Dezembro de 2017, 18:02
 */

#ifndef RASSALTA_H
#define RASSALTA_H
#include "Regra.h"

class RAssalta : public Regra {
public:
    RAssalta();
    bool condicao() override;
    void accao(Formiga* formiga) override;

private:

};

#endif /* RASSALTA_H */

