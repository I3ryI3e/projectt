#include "Ponto.h"
#include <sstream>

Ponto::Ponto(int linha, int coluna): x(linha), y(coluna){}
int Ponto::getX() const{return x;}
int Ponto::getY() const{return y;}
void Ponto::setX(int novox){x = novox;}
void Ponto::setY(int novoy){y = novoy;}
string Ponto::obtemXY() const{
    ostringstream aux;
    aux << "Ponto (" << x << "," << y << ")";
    return aux.str();
}
bool Ponto::operator ==(const Ponto p) const{
    if(x == p.getX() && y == p.getY())
        return true;
    else
        return false;
}
Ponto::~Ponto() {}

