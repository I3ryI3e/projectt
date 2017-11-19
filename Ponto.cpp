#include "Ponto.h"
#include <sstream>

Ponto::Ponto() {
}
int Ponto::getX() const{return x;}
int Ponto::getY() const{return y;}
void Ponto::setX(int novox){x = novox;}
void Ponto::setY(int novoy){y = novoy;}
string Ponto::obtemXY() const{
    ostringstream aux;
    aux << "Ponto (" << x << "," << y << ")";
    return aux.str();
}
Ponto::Ponto(const Ponto& orig) {
}

Ponto::~Ponto() {
}

