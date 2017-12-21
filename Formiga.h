#ifndef FORMIGA_H
#define FORMIGA_H

#include "Ponto.h"
#include "Ninho.h"
class Mundo;
#include "Regra.h"

class Formiga {
    Ponto local_f;
    int energia_f, id_f,energia_inicial,raio_visao,raio_movimento;
    Ninho* ninho_f;
    vector<Regra*> comportamento;
public:
    Formiga(int linha, int coluna, int id,Ninho* ninho_a_que_pertence);
    Ponto getPonto() const;
    string getInfo()const;
    void iteracao(Mundo* mundo_atual);
    void consomeEnergia(int energia);
    void addenergia(int energia);
    virtual ~Formiga();
private:

};

#endif /* FORMIGA_H */

