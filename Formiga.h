#ifndef FORMIGA_H
#define FORMIGA_H

#include "Ponto.h"
#include "Ninho.h"
#include <vector>
class Mundo;
#include "Regra.h"

class Formiga {
    Ponto local_f;
    int energia_f, id_f,energia_inicial,raio_visao,raio_movimento;
    Ninho* ninho_f;
    vector <Regra*> comportamento;
public:
    Formiga(int linha, int coluna, int energ, int id, int energ_init, int rvis, int rmov, Ninho* ninho_a_que_pertence);
    Ponto getPonto() const;
    string getInfo()const;
    int getRaioVisao()const;
    virtual void iteracao(Mundo* mundo_atual, Comunidade* comunidade);
    void consomeEnergia(int energia);
    int getRaioMovimento();
    bool moveFormiga(int x,int y,Mundo* mundo);
    void addenergia(int energia);
    void addRegra(Regra* nregra);
    virtual ~Formiga();
private:

};

#endif /* FORMIGA_H */

