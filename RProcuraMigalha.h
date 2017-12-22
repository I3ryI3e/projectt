/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RProcuraMigalha.h
 * Author: I3ryI3e
 *
 * Created on 22 de Dezembro de 2017, 18:03
 */

#ifndef RPROCURAMIGALHA_H
#define RPROCURAMIGALHA_H
#include "Regra.h"

class RProcuraMigalha : public Regra{
public:
    RProcuraMigalha();
    bool condicao() override;
    void accao(Formiga* formiga) override;

private:

};

#endif /* RPROCURAMIGALHA_H */

