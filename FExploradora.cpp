#include "FExploradora.h"
#include "RVaiParaNinho.h"
#include "RPasseia.h"

FExploradora::FExploradora(int linha, int coluna, int id, Ninho* ninho_a_que_pertence): Formiga(linha,coluna,200,id,10,8,ninho_a_que_pertence) {
   addRegra(new RVaiParaNinho());
   addRegra(new RPasseia());
}

void FExploradora::consomeEnergia(int mov_efetivo) {
    modifica_energia(-(1+mov_efetivo));
}


Formiga* FExploradora::duplica() const {
    return new FExploradora(*this);
}

char FExploradora::getTipo()const{
    if(getenergia() < 100)
        return 'e';
    return 'E';
}
bool FExploradora::ckif_is_to_move_to_ninho() const {
    if(getenergia() > 200 || getenergia()<100)
        return true;
}

float FExploradora::percentage_takes_from_migalha() const {
    return 1;
}






