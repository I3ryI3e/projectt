#include "FExploradora.h"
#include "RPasseia.h"
#include "RProcuraMigalha.h"

FExploradora::FExploradora(int linha, int coluna, int id, Ninho* ninho_a_que_pertence): Formiga(linha,coluna,200,id,10,8,ninho_a_que_pertence) {
   addRegra(new RProcuraMigalha());
}

void FExploradora::consomeEnergia(int mov_efetivo) {
    modifica_energia(-(1+mov_efetivo));
}

char FExploradora::getTipo(){
    if(getenergia() < 100)
        return 'e';
    return 'E';
}

float FExploradora::percentage_takes_from_migalha() const {
    return 1;
}






