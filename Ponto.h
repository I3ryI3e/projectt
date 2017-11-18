#ifndef PONTO_H
#define PONTO_H

#include <iostream>

class Ponto {
    int x, y;
public:
    Ponto();
    int getponto() const;
    void mudaxy(int a, int b);
    Ponto(const Ponto& orig);
    virtual ~Ponto();
private:

};

#endif /* PONTO_H */

