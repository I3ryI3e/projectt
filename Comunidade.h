#ifndef COMUNIDADE_H
#define COMUNIDADE_H

#include <vector>
#include "Ninho.h"
using namespace std;
class Formiga;
class Jogo;

class Comunidade {
    Jogo* p_jogo;
    int n_formigas;
    Ninho ninho;
    vector <Formiga*> formigueiro;
public:
    Comunidade(Jogo* principal, int linha, int coluna, int energ_init_ninho, int def_p_novaformiga, int def_energ_iter);
    bool cckif_space_isempty(int linha, int coluna) const;
    string getInfo()const;
    int getNinhoId()const;
    void setNinhoenerg(int addenerg);
    bool criaFormigas(int quantas, char tipo);
    virtual ~Comunidade();
private:

};

#endif /* COMUNIDADE_H */

