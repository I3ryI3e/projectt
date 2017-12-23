/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RPasseia.cpp
 * Author: I3ryI3e
 * 
 * Created on 22 de Dezembro de 2017, 18:03
 */

#include "RPasseia.h"
#include "Formiga.h"


RPasseia::RPasseia() {
}

void RPasseia::accao(Formiga* formiga, Mundo* mundo) {
    int mov,auxx,auxy,x,y;
    
    do{
            mov = rand() % 4;
            auxx= (rand() % formiga->getRaioMovimento())+1;
            auxy= (rand() % formiga->getRaioMovimento())+1;
            switch(mov){
                case 0:
                    x= auxx;
                    y= 0 -(auxy);
                    break;
                case 1:
                    x= 0 - auxx;
                    y=  auxy;
                    break;
                case 2:
                    x= 0 -auxx;
                    y= 0 -auxy;
                    break;
                case 3:
                    x= auxx;
                    y= 0-auxy;
                    break;
            }
        }while(!formiga->moveFormiga(x,y,mundo));
}

