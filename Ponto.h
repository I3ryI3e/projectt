#ifndef PONTO_H
#define PONTO_H

#include <iostream>
using namespace std;

class Ponto {
    int x, y;
public:
    Ponto();
    int getX()const;
    int getY()const;
    void setX(int novox);
    void setY(int novoy);
    string obtemXY()const;
    Ponto(const Ponto& orig);
    virtual ~Ponto();
private:

};

#endif /* PONTO_H */

