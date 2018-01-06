#include "FSuperman.h"
#include "RSuperman.h"
#include "RComeMigalha.h"
#include "RProcuraMigalha.h"
#include "RPasseia.h"
#include "RFoge.h"

FSuperman::FSuperman(int linha, int coluna, int id, Ninho* ninho_a_que_pertence): Formiga(linha,coluna,200,id,12,10,ninho_a_que_pertence) {
   addRegra(new RSuperman);
   addRegra(new RFoge);
   addRegra(new RComeMigalha);
   addRegra(new RProcuraMigalha);
   addRegra(new RPasseia);
}

void FSuperman::consomeEnergia(int mov_efetivo) {modifica_energia(-(mov_efetivo));}

Formiga* FSuperman::duplica() const {return new FSuperman(*this);}

char FSuperman::getTipo() const {
    if(getenergia() < 100)
            return 's';
        return 'S';
}

float FSuperman::percentage_takes_from_migalha() const {return 1;}

bool FSuperman::ckif_is_to_move_to_ninho() const {
    if(getenergia() > 200 || getenergia()<100)
        return true;
}