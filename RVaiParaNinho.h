/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RVaiParaNinho.h
 * Author: I3ryI3e
 *
 * Created on 22 de Dezembro de 2017, 18:03
 */

#ifndef RVAIPARANINHO_H
#define RVAIPARANINHO_H
#include "Regra.h"

class RVaiParaNinho : public Regra{
public:
    RVaiParaNinho();
    bool condicao() override;
    void accao(Formiga* formiga) override;

private:

};

#endif /* RVAIPARANINHO_H */
