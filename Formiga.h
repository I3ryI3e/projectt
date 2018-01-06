#ifndef FORMIGA_H
#define FORMIGA_H

#include "Ponto.h"
#include "Ninho.h"
#include <vector>
class Mundo;
#include "Regra.h"

class Formiga {
    Ponto local_f;
    int id_f, raio_visao, raio_movimento, n_iteracoes_sem_ir_ao_ninho;
    float energia_f;
    Ninho* ninho_f;
    vector <Regra*> comportamento;
public:
    Formiga(int linha, int coluna, float energ, int id, int rvis, int rmov, Ninho* ninho_a_que_pertence);
    Formiga(const Formiga& outro);
    Formiga& operator=(Formiga& outro);
    Ponto getPonto() const;
    string getInfo() const;
    int getRaioVisao() const;
    int getNIteracoesSemNinho() const;
    void resetNIteracoesSemNinho();
    virtual bool ckif_is_to_move_to_ninho() const = 0;
    bool ckif_ninho_in_raio_visao();
    float getenergia() const;
    void iteracao(Mundo* mundo_atual, Comunidade* comunidade);
    virtual void consomeEnergia(int mov_efetivo) = 0;
    virtual Formiga* duplica() const = 0;
    int getRaioMovimento() const;
    virtual float percentage_takes_from_migalha() const = 0;
    bool moveFormiga(int x, int y, Mundo* mundo);
    void modifica_energia(float energia);
    void addRegra(Regra* nregra);
    virtual char getTipo() const = 0;
    void mov_SuperFormiga(int linha, int coluna);
    virtual ~Formiga();
private:
};

#endif /* FORMIGA_H */

