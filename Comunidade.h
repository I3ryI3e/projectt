#ifndef COMUNIDADE_H
#define COMUNIDADE_H

#include <vector>
#include "Ninho.h"
using namespace std;
class Formiga;
class Mundo;

class Comunidade {
    Mundo* p_mundo;
    int n_formigas, contador_formigas;
    Ninho ninho;
    vector <Formiga*> formigueiro;
public:
    Comunidade(Mundo* principal, int linha, int coluna, float energ_init_ninho, int def_p_novaformiga, int def_energ_iter);
    Comunidade(const Comunidade& outro);
    Comunidade& operator=(Comunidade outro);
    void swap(Comunidade& outro);
    bool cckif_space_isempty(int linha, int coluna) const;
    string getInfoGeral() const;
    string getInfoNinho() const;
    void trataResetNNinhos();
    string ckwhoisthere(const Ponto &aux) const;
    bool ckif_formigas_no_raio(Ponto local_origem, int raio) const;
    bool ckif_formiga_da_mesma_comunidade_num_raio_visao(Ponto local_origem, int raio_visao) const;
    int ckif_formiga_num_raio_visao_quadrante(Ponto local_origem, int raio_visao, int formiga_x) const;
    bool ckif_formigas_no_ninho()const;
    Ponto local_formiga_com_mais_energia(int raio, Ponto local_formiga) const;
    Ponto local_formiga_mesma_comunidade_com_menos_energia(Ponto local_formiga) const;
    Ponto local_formiga_a_proteger(int raio, Ponto local_formiga) const;
    int getNinhoId() const;
    Ponto getNinhoPonto() const;
    void setNinhoenerg(float addenerg);
    void setMundo(Mundo* mundo);
    bool criaFormigas(int quantas, char tipo);
    bool cria1Formiga(char tipo, int linha, int coluna);
    float born_new_formiga_in_ninho();
    void iteracao();
    int getNFormigas() const;
    bool addenergFormiga(int linha, int coluna, float energ);
    Ponto getPontoFormiga(int num) const;
    char getTipoFormiga(int num) const;
    float try_totake_EnergiaFormiga(Ponto aux);
    float formiga_gives_energy_to_ninho();
    float formiga_try_to_take_energy_from_ninho();
    bool mataformiga(int linha, int coluna);
    void remove_Dead_Formigas();
    void ninho_set_def_p_novaformiga(int novo_valor);
    void ninho_set_def_energ_iter(int novo_valor);
    virtual ~Comunidade();
private:
};

#endif /* COMUNIDADE_H */

