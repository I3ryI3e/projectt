#ifndef JOGO_H
#define JOGO_H
#include <vector>
using namespace std;
#include "Comunidade.h"
#include "Migalha.h"

class Jogo {
    vector <Comunidade> comunidades;
    vector <Migalha> migalhas;
    int limite,energ_init_ninho,def_p_novaformiga,def_energ_iter;
    int p_init_migalhas,energ_init_migalhas,migalhas_iter;
public:
    Jogo();
    void configuracao();
    int getLimite()const;
    int tratacmd(string linha, int estado);
    void crianinho(int linha, int coluna);
    bool jckif_space_isempty(int linha, int coluna)const;
    bool ckif_notconfig()const;
    bool criaformigas(int quantas, char tipo, int id_n);
    Jogo(const Jogo& orig);
    virtual ~Jogo();
private:

};

#endif /* JOGO_H */

