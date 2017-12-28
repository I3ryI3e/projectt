#include "Migalha.h"
#include <sstream>

Migalha::Migalha(int linha, int coluna, int energini): local_m(linha, coluna), energia_m(energini), energia_inicial(energini){
}

Ponto Migalha::getPonto() const{return local_m;}
string Migalha::getInfo() const{
    ostringstream oss;
    oss << "Local: " << local_m.obtemXY() << "\tEnergia: " << energia_m;
    return oss.str();
}

int Migalha::getEnergia() const{
    return energia_m;
}

int Migalha::loseEnergy(int percentage_of_energy_to_take) {
    int aux;
    if(energia_m-percentage_of_energy_to_take < 0 ){
        aux=energia_m;
        energia_m=0;
        return aux;     
    }else{
        energia_m-=percentage_of_energy_to_take;
        return percentage_of_energy_to_take;
    }    
}

void Migalha::iteracao(){
    if(energia_m > (energia_inicial/10)){
        --energia_m;
    }
}

Migalha::~Migalha() {
}

