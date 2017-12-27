#include "FVigilante.h"

FVigilante::FVigilante(int linha, int coluna, int id, Ninho* ninho_a_que_pertence): Formiga(linha,coluna,150,id,150,7,5,ninho_a_que_pertence) {
}

void FVigilante::consomeEnergia(int mov_efetivo) {
    modifica_energia(-(1+mov_efetivo));
}


FVigilante::~FVigilante() {

}



