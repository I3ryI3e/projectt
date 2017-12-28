#include "Formiga.h"
#include "Mundo.h"
#include <sstream>
#include <ctime>
Formiga::Formiga(int linha, int coluna, float energ, int id, int rvis, int rmov, Ninho* ninho_a_que_pertence): local_f(linha, coluna), energia_f(energ),id_f(id), energia_inicial(energ), raio_visao(rvis), raio_movimento(rmov), ninho_f(ninho_a_que_pertence){    
}

string Formiga::getInfo() const{
    ostringstream oss;
    oss << "Formiga " << id_f << "->" << "\tLocal: " << local_f.obtemXY() << "\tEnergia: " << energia_f;
    return oss.str();
}

Ponto Formiga::getPonto() const{return local_f;}

int Formiga::getRaioVisao() const{return raio_visao;}

float Formiga::getenergia() const{return energia_f;}

void Formiga::iteracao(Mundo* mundo_atual, Comunidade* comunidade){
    
    auto it =comportamento.begin();
    while(it != comportamento.end()){
        if((*it)->condicao(this, mundo_atual, comunidade)){
            (*it)->accao(this, mundo_atual, comunidade);
            it=comportamento.end();
        }else
            it++;
    }
}

int Formiga::getRaioMovimento(){
    return raio_movimento;
}
bool Formiga::moveFormiga(int x, int y,Mundo* mundo){
    if((((local_f.getX()+x) == ninho_f->getPonto().getX()) && ((local_f.getY()+y) == ninho_f->getPonto().getY())) || (x==0 && y==0)){
        local_f.setX(local_f.getX()+x);
        local_f.setY(local_f.getY()+y);
        consomeEnergia((abs(x)+abs(y)));
        return true;
    }
    if(mundo->mckif_noants_nonest((local_f.getX()+x),(local_f.getY()+y))){
        local_f.setX(local_f.getX()+x);
        local_f.setY(local_f.getY()+y);
        consomeEnergia((abs(x)+abs(y)));
        return true;
    } else{
        return false;
    }
}

void Formiga::addRegra(Regra* nregra){
    comportamento.push_back(nregra);
}
void Formiga::modifica_energia(float energia){
    energia_f += energia;
}
Formiga::~Formiga() {
    auto it = comportamento.begin();
    while(it != comportamento.end()){
        delete (*it);
        it++;
    }
    comportamento.clear();
}

