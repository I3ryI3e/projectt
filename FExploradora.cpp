#include "FExploradora.h"
#include "RPasseia.h"
#include "RFoge.h"

FExploradora::FExploradora(int linha, int coluna, int id, Ninho* ninho_a_que_pertence): Formiga(linha,coluna,200,id,200,10,8,ninho_a_que_pertence) {
   addRegra(new RFoge);
}

void FExploradora::iteracao(Mundo* mundo_atual, Comunidade* comunidade) {
    Formiga::iteracao(mundo_atual, comunidade);
}

FExploradora::~FExploradora() {

}



