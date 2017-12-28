#include "FAssaltante.h"

FAssaltante::FAssaltante(int linha, int coluna, int id, Ninho* ninho_a_que_pertence): Formiga(linha,coluna,80,id,8,4,ninho_a_que_pertence) {

}

void FAssaltante::consomeEnergia(int mov_efetivo) {
    modifica_energia(-((mov_efetivo*2)+1));
}


FAssaltante::~FAssaltante() {

}

