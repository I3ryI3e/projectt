#include "Comunidade.h"
#include "Ponto.h"
#include "Formiga.h"
#include "Jogo.h"
#include <sstream>
#include <random>
#include <ctime>

Comunidade::Comunidade(Jogo* principal, int linha, int coluna, int energ_init_ninho, int def_p_novaformiga, int def_energ_iter): p_jogo(principal),ninho(linha, coluna,
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
    oss << "Comunidade" << endl << ninho.getInfo()<< "Numero de Formigas:" << formigueiro.size() << endl;
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
                r_linha= rand() % p_jogo->getLimite();
                r_coluna= rand() % p_jogo->getLimite();
            }while(p_jogo->jckif_space_isempty(r_linha,r_coluna) == false);
                formigueiro.push_back(new Formiga(r_linha,r_coluna,++n_formigas,&ninho));
        }
        return true;
    }
    return false;
}
void Comunidade::iteracao(){
    ninho.iteracao(this);
    auto it= formigueiro.begin();
    while(it != formigueiro.end()){
        (*it)->iteracao(p_jogo);
        ++it;
    }
}
int Comunidade::getNFormigas() const{
    return n_formigas;
}
void Comunidade::addenergFormiga(int linha, int coluna, int energ){
    Ponto aux(linha, coluna);
    auto it = formigueiro.begin();
    while(it != formigueiro.end()){
        if(aux == (*it)->getPonto()){
            (*it)->addenergia(energ);
            return;
        }
        ++it;
    }
}
Ponto Comunidade::getPontoFormiga(int num) const{
    return formigueiro.at(num)->getPonto();
}
Comunidade::~Comunidade() {
    auto it= formigueiro.begin();
    while(it != formigueiro.end()){
        delete (*it);
        it=formigueiro.erase(it);
    }
}

