#include "FCuidadora.h"

FCuidadora::FCuidadora(int linha, int coluna, int id, Ninho* ninho_a_que_pertence): Formiga(linha,coluna,100,id,5,3,ninho_a_que_pertence) {
}

void FCuidadora::consomeEnergia(int mov_efetivo) {
    modifica_energia(-(1+mov_efetivo));
}

FCuidadora::~FCuidadora() {

}



