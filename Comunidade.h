#ifndef COMUNIDADE_H
#define COMUNIDADE_H

#include <vector>
#include "Ninho.h"
using namespace std;
class Formiga;
class Mundo;

class Comunidade {
    Mundo* p_mundo;
    int n_formigas;
    Ninho ninho;
    vector <Formiga*> formigueiro;
public:
    Comunidade(Mundo* principal, int linha, int coluna, int energ_init_ninho, int def_p_novaformiga, int def_energ_iter);
    bool cckif_space_isempty(int linha, int coluna) const;
    string getInfoGeral() const;
    string getInfoNinho() const;
    string ckwhoisthere(const Ponto &aux) const;
    int getNinhoId() const;
    Ponto getNinhoPonto() const;
    void setNinhoenerg(int addenerg);
    bool criaFormigas(int quantas, char tipo);
    void iteracao();
    int getNFormigas()const;
    void addenergFormiga(int linha, int coluna, int energ);
    Ponto getPontoFormiga(int num) const;
    virtual ~Comunidade();
private:

};

#endif /* COMUNIDADE_H */

