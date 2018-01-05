#include "Migalha.h"
#include <sstream>

Migalha::Migalha(int linha, int coluna, float energini): local_m(linha, coluna), energia_m(energini), energia_inicial(energini){}

Ponto Migalha::getPonto() const{return local_m;}

string Migalha::getInfo() const{
    ostringstream oss;
    oss << "Local: " << local_m.obtemXY() << "\tEnergia: " << energia_m;
    return oss.str();
}

float Migalha::getEnergia() const{return energia_m;}

float Migalha::loseEnergy(float percentage_of_energy_to_take) {
    int aux=energia_m;
    energia_m*=(1-percentage_of_energy_to_take);
    return aux-energia_m;
}

void Migalha::iteracao(){
    if(energia_m > (energia_inicial/10)){
        --energia_m;
    }
}

Migalha::~Migalha() {}

