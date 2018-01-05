#include "FVigilante.h"
#include "RProtege.h"
#include "RComeMigalha.h"
#include "RProcuraMigalha.h"
#include "RPasseia.h"

FVigilante::FVigilante(int linha, int coluna, int id, Ninho* ninho_a_que_pertence): Formiga(linha,coluna,150,id,7,5,ninho_a_que_pertence) {
    addRegra(new RProtege());
    addRegra(new RComeMigalha);
    addRegra(new RProcuraMigalha);
    addRegra(new RPasseia);
}

void FVigilante::consomeEnergia(int mov_efetivo) {modifica_energia(-(1+mov_efetivo));}

Formiga* FVigilante::duplica() const {return new FVigilante(*this);}

float FVigilante::percentage_takes_from_migalha() const {return 0.75;}

char FVigilante::getTipo() const {
    if(getenergia() < 75)
        return 'v';
    return 'V';
}
bool FVigilante::ckif_is_to_move_to_ninho() const {
    if(getenergia() > 150 || getenergia()<75)
        return true;
}

FVigilante::~FVigilante() {}