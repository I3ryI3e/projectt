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
    int limite,def_p_novaformiga,def_energ_iter;
    int p_init_migalhas,migalhas_iter;
    float energ_init_ninho,energ_init_migalhas;
public:
    Mundo();
    void configuracao();
    int getLimite() const;
    int tratacmd(string linha, int estado);
    void crianinho(int linha, int coluna);
    void criamigalha(int linha, int coluna);
    bool mckif_space_isempty(int linha, int coluna) const;
    bool mckif_noants_nonest(int linha,int coluna)const;
    bool ckif_notconfig() const;
    bool criaformigas(int quantas, char tipo, int id_n);
    bool cria1formiga(char tipo, int id_n, int linha, int coluna);
    bool ckif_formigas_no_raio_visao(Comunidade* comunidade, int raio_de_visao, Ponto local_formiga);
    bool ckif_migalha_adjacente(Ponto local_formiga)const;
    bool ckif_migalhas_no_raio_visao(int raio_de_visao,Ponto local_formiga);
    Ponto local_migalha_com_mais_energia(int raio_de_visao,Ponto local_formiga);
    Ponto local_formiga_enemy(int raio_de_visao,Ponto local_formiga,Comunidade* comunidade);
    int  best_quadrante_to_runaway(Comunidade* comunidade, int raio_de_visao, Ponto local_formiga);
    void migalhas_iniciais();
    void novas_migalhas_iter();
    void updatemap();
    float try_to_get_energy_from_migalha(Ponto aux, float percentage);
    Mundo(const Mundo& orig);
    virtual ~Mundo();
private:

};

#endif /* MUNDO_H */

