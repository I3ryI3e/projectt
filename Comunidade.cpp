#include "Comunidade.h"
#include "Ponto.h"
#include "Formiga.h"
#include "Mundo.h"
#include "FExploradora.h"
#include <sstream>
#include <random>
#include <ctime>
#include <cstdlib>

Comunidade::Comunidade(Mundo* principal, int linha, int coluna, int energ_init_ninho, int def_p_novaformiga, int def_energ_iter): p_mundo(principal),ninho(linha, coluna,
        energ_init_ninho, def_p_novaformiga, def_energ_iter),n_formigas(0){}

bool Comunidade::cckif_space_isempty(int linha, int coluna) const{
    Ponto aux(linha, coluna);
    if(aux == ninho.getPonto()){
        return false;
    }else{
        auto it = formigueiro.cbegin();
        while(it != formigueiro.cend()){
            if(aux == (*it)->getPonto())
                return false;
            ++it;
        }
    }
    return true;
}
string Comunidade::getInfoGeral() const{
    ostringstream oss;
    oss << "Comunidade" << endl << ninho.getInfo() << "Numero de Formigas:" << formigueiro.size() << endl;
    return oss.str();
}
string Comunidade::getInfoNinho() const{
    ostringstream oss;
    oss << ninho.getInfo() << endl;
    auto it = formigueiro.cbegin();
    while(it != formigueiro.cend()){
        oss << (*it)->getInfo() << endl;
        ++it;
    }
    return oss.str();
}
string Comunidade::ckwhoisthere(const Ponto& aux) const{
    ostringstream oss;
    if(aux == ninho.getPonto())
        oss << ninho.getInfo()<< endl;
    auto it = formigueiro.cbegin();
    while(it != formigueiro.cend()){
        if((*it)->getPonto()== aux){
            oss << (*it)->getInfo() << endl;
        }
        ++it;
    }
    return oss.str();
}

bool Comunidade::ckif_formigas_num_raio_visao(Ponto local_origem, int raio_visao) const {
    auto it = formigueiro.cbegin();
    while(it != formigueiro.cend()){
        if((abs(local_origem.getX()-(*it)->getPonto().getX()) <= raio_visao) && (abs(local_origem.getY()-(*it)->getPonto().getY()) <= raio_visao) )
            return true;
        ++it;
    }
    return false;
}

int Comunidade::ckif_formiga_num_raio_visao_quadrante(Ponto local_origem, int raio_visao, int formiga_x) const {
    int auxx,auxy;
    if((abs(local_origem.getX()-(formigueiro.at(formiga_x)->getPonto().getX())) <= raio_visao) && (abs(local_origem.getY()-(formigueiro.at(formiga_x)->getPonto().getY()))<=raio_visao)){
        auxx=local_origem.getX()-formigueiro.at(formiga_x)->getPonto().getX();
        auxy=local_origem.getY()-formigueiro.at(formiga_x)->getPonto().getY();
        if(auxx >=0){
            if(auxy>=0)
                return 2;
            else
                return 1;
        }else{
            if(auxy>=0)
                return 3;
            else
                return 0;
        }
    } else
        return -1;
}


int Comunidade::getNinhoId() const{
    return ninho.getId();
}
Ponto Comunidade::getNinhoPonto() const{
    return ninho.getPonto();
}
void Comunidade::setNinhoenerg(int addenerg){
    ninho.setenergia_n(addenerg);
}
bool Comunidade::criaFormigas(int quantas, char tipo){
    srand (time(NULL));
    if(tipo == 'E'){
        for(int i=0;i<quantas;i++){
            int r_linha, r_coluna;
            do{
                r_linha= rand() % p_mundo->getLimite();
                r_coluna= rand() % p_mundo->getLimite();
            }while(p_mundo->mckif_space_isempty(r_linha,r_coluna) == false);
                formigueiro.push_back(new FExploradora(r_linha,r_coluna,++n_formigas,&ninho));
        }
        return true;
    }
    return false;
}
void Comunidade::iteracao(){
    ninho.iteracao(this);
    auto it= formigueiro.begin();
    while(it != formigueiro.end()){
        (*it)->iteracao(p_mundo, this);
        ++it;
    }
}
int Comunidade::getNFormigas() const{
    return n_formigas;
}
bool Comunidade::addenergFormiga(int linha, int coluna, int energ){
    Ponto aux(linha, coluna);
    auto it = formigueiro.begin();
    while(it != formigueiro.end()){
        if(aux == (*it)->getPonto())
            (*it)->addenergia(energ);
            return true;
        ++it;
    }
    return false;
}
Ponto Comunidade::getPontoFormiga(int num) const{
    return formigueiro.at(num)->getPonto();
}
//bool Comunidade::mataformiga(int linha, int coluna){
//    Ponto aux(linha, coluna);
//    auto it= formigueiro.begin();
//    while(it != formigueiro.end()){
//        if((*it)->getPonto() == aux){
//            delete (*it);
//            it=formigueiro.erase(it);
//            return true;
//        }
//        ++it;
//    }
//    return false;
//}
Comunidade::~Comunidade() {
    auto it= formigueiro.begin();
    while(it != formigueiro.end()){
        delete (*it);
        it=formigueiro.erase(it);
    }
}

