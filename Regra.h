#ifndef REGRA_H
#define REGRA_H
class Formiga;
class Mundo;
class Comunidade;

class Regra {
public:
    Regra();
    virtual bool condicao(Formiga* formiga, Mundo* mundo, Comunidade* comunidade);
    virtual void accao(Formiga* formiga, Mundo* mundo) = 0;
    virtual ~Regra();
private:

};

#endif /* REGRA_H */

