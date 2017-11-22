#ifndef FORMIGA_H
#define FORMIGA_H

#include "Ponto.h"
#include "Ninho.h"

class Formiga {
    Ponto local_f;
    int energia_f, id_f;
    Ninho* ninho_f;
public:
    Formiga(int linha, int coluna);
    Ponto getPonto() const;
    virtual ~Formiga();
private:

};

#endif /* FORMIGA_H */

