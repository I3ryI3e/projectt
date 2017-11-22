#include "Comunidade.h"
#include "Ponto.h"
#include "Formiga.h"

Comunidade::Comunidade(int linha, int coluna, int energ_init_ninho, int def_p_novaformiga, int def_energ_iter): ninho(linha, coluna,
        energ_init_ninho, def_p_novaformiga, def_energ_iter){}

bool Comunidade::cckif_space_isempty(int linha, int coluna) const{
    Ponto aux(linha, coluna);
    if(aux == ninho.getPonto()){
        return false;
    }else{
        auto it = formigueiro.cbegin();
        while(it != formigueiro.cend()){
            if(aux == (*it)->getPonto())
                return false;
            ++it;
        }
    }
    return true;
}

Comunidade::~Comunidade() {
}

