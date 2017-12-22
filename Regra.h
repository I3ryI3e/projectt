/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Regra.h
 * Author: I3ryI3e
 *
 * Created on 21 de Dezembro de 2017, 18:08
 */

#ifndef REGRA_H
#define REGRA_H
class Formiga;

class Regra {
public:
    Regra();
    virtual bool condicao();
    virtual void accao(Formiga* formiga) = 0;
    virtual ~Regra();
private:

};

#endif /* REGRA_H */

