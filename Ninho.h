#ifndef NINHO_H
#define NINHO_H

#include "Ponto.h"

class Ninho {
    Ponto local_n;
    int energ_iter, p_novaformiga,energia_n, id_n;
    static int n_ninhos;
public:
    Ninho();
    Ninho(const Ninho& orig);
    virtual ~Ninho();
private:

};

#endif /* NINHO_H */

