#include "Ninho.h"

int Ninho::n_ninhos = 1;

Ninho::Ninho(int linha, int coluna, int energ_init_ninho, int def_p_novaformiga, int def_energ_iter): local_n(linha, coluna),
        energia_n(energ_init_ninho), p_novaformiga(def_p_novaformiga), energ_iter(def_energ_iter), id_n(n_ninhos++){}

Ponto Ninho::getPonto() const{return local_n;}

Ninho::~Ninho() {
}

