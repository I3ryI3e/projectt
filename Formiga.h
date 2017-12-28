#ifndef FORMIGA_H
#define FORMIGA_H

#include "Ponto.h"
#include "Ninho.h"
#include <vector>
class Mundo;
#include "Regra.h"

class Formiga {
    Ponto local_f;
    int id_f,raio_visao,raio_movimento;
    float energia_f,energia_inicial;
    Ninho* ninho_f;
    vector <Regra*> comportamento;
public:
    Formiga(int linha, int coluna, float energ, int id, int rvis, int rmov, Ninho* ninho_a_que_pertence);
    Ponto getPonto() const;
    string getInfo() const;
    int getRaioVisao() const;
    float getenergia() const;
    void iteracao(Mundo* mundo_atual, Comunidade* comunidade);
    virtual void consomeEnergia(int mov_efetivo) = 0;
    int getRaioMovimento();
    virtual float percentage_takes_from_migalha()const = 0;
    bool moveFormiga(int x,int y,Mundo* mundo);
    void modifica_energia(float energia);
    void addRegra(Regra* nregra);
    virtual ~Formiga();
private:

};

#endif /* FORMIGA_H */

