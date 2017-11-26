#include "Migalha.h"
#include <sstream>

Migalha::Migalha(int linha, int coluna, int energini): local_m(linha, coluna), energia_m(energini){
}

Ponto Migalha::getPonto() const{return local_m;}
string Migalha::getInfo() const{
    ostringstream oss;
    oss << "Local: " << local_m.obtemXY() << endl << "Energia: " << energia_m;
    return oss.str();
}

Migalha::~Migalha() {
}

