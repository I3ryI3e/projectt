#include "Migalha.h"

Migalha::Migalha(int linha, int coluna): local_m(linha, coluna){
}

Ponto Migalha::getPonto() const{return local_m;}

Migalha::~Migalha() {
}

