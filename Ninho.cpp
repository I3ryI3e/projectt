#include "Ninho.h"
#include "Comunidade.h"
#include <sstream>

int Ninho::n_ninhos = 0;

Ninho::Ninho(int linha, int coluna, int energ_init_ninho, int def_p_novaformiga, int def_energ_iter): local_n(linha, coluna),
        energia_n(energ_init_ninho), p_novaformiga(def_p_novaformiga), energ_iter(def_energ_iter), id_n(++n_ninhos), energia_inicial(energ_init_ninho){}

Ponto Ninho::getPonto() const{return local_n;}

string Ninho::getInfo() const{
    ostringstream oss;
    oss << "Ninho " << id_n << "->\t" << "Local: " << local_n.obtemXY() << "\tEnergia: " << energia_n << endl;
    return oss.str();
}
int Ninho::getId() const{
    return id_n;
}
bool Ninho::setenergia_n(int addenerg){
    if(energia_n + addenerg > 0){
        energia_n += addenerg;
        return true;
    }
    return false;
}
int Ninho::getEnerg_Iter() const{
    return energ_iter;
}

void Ninho::iteracao(Comunidade* sua_Comunidade){
    if(energia_n >= energia_inicial+(energia_inicial*((float)p_novaformiga/100))){
        sua_Comunidade->criaFormigas(1,'E');                                     // TEM QUE SER MUDADO   
    }
}
Ninho::~Ninho() {
}

