#ifndef NINHO_H
#define NINHO_H

#include "Ponto.h"
class Comunidade;

class Ninho {
    Ponto local_n;
    int energia_n, p_novaformiga, energ_iter, id_n,energia_inicial;
    static int n_ninhos;
public:
    Ninho(int linha, int coluna, int energ_init_ninho, int def_p_novaformiga, int def_energ_iter);
    Ponto getPonto() const;
    string getInfo()const;
    int getId()const;
    bool setenergia_n(int addenerg);
    void iteracao(Comunidade* sua_comunidade);
    int getEnerg_Iter()const;
    virtual ~Ninho();
private:

};

#endif /* NINHO_H */

