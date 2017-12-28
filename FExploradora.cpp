#include "FExploradora.h"
#include "RPasseia.h"
#include "RComeMigalha.h"

FExploradora::FExploradora(int linha, int coluna, int id, Ninho* ninho_a_que_pertence): Formiga(linha,coluna,200,id,10,8,ninho_a_que_pertence) {
   addRegra(new RComeMigalha());
}

void FExploradora::consomeEnergia(int mov_efetivo) {
    modifica_energia(-(1+mov_efetivo));
}

float FExploradora::percentage_takes_from_migalha() const {
    return 1;
}






