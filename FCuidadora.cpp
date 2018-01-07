#include "FCuidadora.h"
#include "RFoge.h"
#include "RComeMigalha.h"
#include "RProcuraMigalha.h"
#include "RVaiParaNinho.h"
#include "RPasseia.h"

FCuidadora::FCuidadora(int linha, int coluna, int id, Ninho* ninho_a_que_pertence): Formiga(linha,coluna,100,id,5,3,ninho_a_que_pertence) {
    addRegra(new RFoge);
    addRegra(new RComeMigalha);
    addRegra(new RProcuraMigalha);
    addRegra(new RVaiParaNinho);
    addRegra(new RPasseia);
}

void FCuidadora::consomeEnergia(int mov_efetivo) {modifica_energia(-(1+mov_efetivo));}

float FCuidadora::percentage_takes_from_migalha() const {return 0.5;}

Formiga* FCuidadora::duplica() const {return new FCuidadora(*this);}

char FCuidadora::getTipo() const {
    if(getenergia() < 50)
        return 'c';
    return 'C';
}

bool FCuidadora::ckif_is_to_move_to_ninho() const {
    if(getenergia() > 100 || getenergia()<50)
        return true;
    return false;
}

FCuidadora::~FCuidadora() {}