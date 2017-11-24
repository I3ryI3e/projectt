#include "Ninho.h"
#include <sstream>

int Ninho::n_ninhos = 0;

Ninho::Ninho(int linha, int coluna, int energ_init_ninho, int def_p_novaformiga, int def_energ_iter): local_n(linha, coluna),
        energia_n(energ_init_ninho), p_novaformiga(def_p_novaformiga), energ_iter(def_energ_iter), id_n(++n_ninhos){}

Ponto Ninho::getPonto() const{return local_n;}

string Ninho::getInfo() const{
    ostringstream oss;
    oss << "Ninho " << id_n << ":" << endl << "Local: " << local_n.obtemXY() << endl << "Energia: " << energia_n;
    return oss.str();
}
int Ninho::getId() const{
    return id_n;
}
void Ninho::setenergia_n(int addenerg){
    if(energia_n + addenerg > 0)
        energia_n += addenerg;
}
Ninho::~Ninho() {
}

