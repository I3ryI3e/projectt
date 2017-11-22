#ifndef PONTO_H
#define PONTO_H

#include <iostream>
using namespace std;

class Ponto {
    int x, y;
public:
    Ponto(int linha, int coluna);
    int getX()const;
    int getY()const;
    void setX(int novox);
    void setY(int novoy);
    string obtemXY()const;
    bool operator== (const Ponto p) const;
    virtual ~Ponto();
private:

};

#endif /* PONTO_H */

