#ifndef MUNDO_H
#define MUNDO_H
#include <vector>
#include "Comunidade.h"
#include "Migalha.h"
#include "Interface.h"

using namespace std;

class Mundo {
    vector <Comunidade> comunidades;
    vector <Migalha> migalhas;
    int limite,energ_init_ninho,def_p_novaformiga,def_energ_iter;
    int p_init_migalhas,energ_init_migalhas,migalhas_iter;
public:
    Mundo();
    void configuracao();
    int getLimite() const;
    int tratacmd(string linha, int estado);
    void crianinho(int linha, int coluna);
    void criamigalha(int linha, int coluna);
    bool mckif_space_isempty(int linha, int coluna) const;
    bool ckif_notconfig() const;
    bool criaformigas(int quantas, char tipo, int id_n);
    bool ckif_formigas_no_raio_visao(Comunidade* comunidade,       int raio_de_visao, Ponto local_formiga);
    int  best_quadrante_to_runaway(Comunidade* comunidade, int raio_de_visao, Ponto local_formiga);
    void migalhas_iniciais();
    void novas_migalhas_iter();
    void updatemap();
    Mundo(const Mundo& orig);
    virtual ~Mundo();
private:

};

#endif /* MUNDO_H */

