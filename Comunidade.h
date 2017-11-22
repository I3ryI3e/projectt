#ifndef COMUNIDADE_H
#define COMUNIDADE_H

#include <vector>
#include "Ninho.h"
using namespace std;
class Formiga;

class Comunidade {
    Ninho ninho;
    vector <Formiga*> formigueiro;
public:
    Comunidade(int linha, int coluna, int energ_init_ninho, int def_p_novaformiga, int def_energ_iter);
    bool cckif_space_isempty(int linha, int coluna) const;
    virtual ~Comunidade();
private:

};

#endif /* COMUNIDADE_H */

