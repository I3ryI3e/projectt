#ifndef NINHO_H
#define NINHO_H

#include "Ponto.h"
#include <sstream>
class Comunidade;
class Formiga;

class Ninho {
    Ponto local_n;
    int p_novaformiga, energ_iter, id_n;
    float energia_n, energia_inicial;
    static int n_ninhos;
public:
    Ninho(int linha, int coluna, float energ_init_ninho, int def_p_novaformiga, int def_energ_iter);
    Ponto getPonto() const;
    string getInfo() const;
    void resetN_Ninhos();
    float getEnergy() const;
    int getId() const;
    bool setenergia_n(float addenerg);
    float get_energy_from_formiga();
    float give_energy_to_formiga();
    void iteracao(Comunidade* sua_comunidade);
    int getEnerg_Iter() const;
    void set_def_p_novaformiga(int novo_valor);
    void set_def_energ_iter(int novo_valor);
    virtual ~Ninho();
private:
};

#endif /* NINHO_H */

