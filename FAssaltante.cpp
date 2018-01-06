#include "FAssaltante.h"
#include "RAssalta.h"
#include "RPersegue.h"
#include "RComeMigalha.h"
#include "RProcuraMigalha.h"
#include "RPasseia.h"

FAssaltante::FAssaltante(int linha, int coluna, int id, Ninho* ninho_a_que_pertence): Formiga(linha,coluna,80,id,8,4,ninho_a_que_pertence) {
    addRegra(new RAssalta);
    addRegra(new RPersegue);
    addRegra(new RComeMigalha);
    addRegra(new RProcuraMigalha);
    addRegra(new RPasseia);
}

void FAssaltante::consomeEnergia(int mov_efetivo) {modifica_energia(-((mov_efetivo*2)+1));}

Formiga* FAssaltante::duplica() const {return new FAssaltante(*this);}

float FAssaltante::percentage_takes_from_migalha() const {return 0.25;}

char FAssaltante::getTipo() const {
    if(getenergia() < 40)
            return 'a';
        return 'A';
}

bool FAssaltante::ckif_is_to_move_to_ninho() const {
    if(getenergia() > 80 || getenergia()<40)
        return true;
}

FAssaltante::~FAssaltante() {}