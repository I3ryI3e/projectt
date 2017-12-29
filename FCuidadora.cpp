#include "FCuidadora.h"

FCuidadora::FCuidadora(int linha, int coluna, int id, Ninho* ninho_a_que_pertence): Formiga(linha,coluna,100,id,5,3,ninho_a_que_pertence) {
}

void FCuidadora::consomeEnergia(int mov_efetivo) {
    modifica_energia(-(1+mov_efetivo));
}

float FCuidadora::percentage_takes_from_migalha() const {

}


Formiga* FCuidadora::duplica() const {
    return new FCuidadora(*this);
}

char FCuidadora::getTipo() const {
    if(getenergia() < 50)
        return 'c';
    return 'C';
}


FCuidadora::~FCuidadora() {

}



