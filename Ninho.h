/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ninho.h
 * Author: I3ryI3e
 *
 * Created on 18 de Novembro de 2017, 14:34
 */

#ifndef NINHO_H
#define NINHO_H

class Ninho {
    Ponto local_n;
    int energ_iter, p_novaformiga, energia_n, id_n;
    static int n_ninhos;
public:
    Ninho();
    Ninho(const Ninho& orig);
    virtual ~Ninho();
private:

};

#endif /* NINHO_H */

