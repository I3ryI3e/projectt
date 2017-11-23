#include "Formiga.h"
#include <sstream>
Formiga::Formiga(int linha, int coluna, int id): local_f(linha, coluna), energia_f(200), id_f(id){    //ACABAR
}

string Formiga::getInfo() const{
    ostringstream oss;
    oss << "Formiga " << id_f << ":" << endl << "Local: " << local_f.obtemXY() << endl << "Energia: " << energia_f;
    return oss.str();
}

Ponto Formiga::getPonto() const{return local_f;}

Formiga::~Formiga() {
}

