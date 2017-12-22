/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FExploradora.h
 * Author: I3ryI3e
 *
 * Created on 21 de Dezembro de 2017, 18:21
 */

#ifndef FEXPLORADORA_H
#define FEXPLORADORA_H
#include "Formiga.h"

class FExploradora : public Formiga{
public:
    FExploradora(int linha, int coluna, int id, Ninho* ninho_a_que_pertence);
    void iteracao(Mundo* mundo_atual) override;

private:

};

#endif /* FEXPLORADORA_H */

