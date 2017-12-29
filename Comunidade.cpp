#include "Comunidade.h"
#include "Ponto.h"
#include "Formiga.h"
#include "Mundo.h"
#include "FExploradora.h"
#include <sstream>
#include <random>
#include <ctime>
#include <cstdlib>

Comunidade::Comunidade(Mundo* principal, int linha, int coluna, float energ_init_ninho, int def_p_novaformiga, int def_energ_iter): p_mundo(principal),ninho(linha, coluna,
        energ_init_ninho, def_p_novaformiga, def_energ_iter),n_formigas(0){
}

Comunidade::Comunidade(const Comunidade& outro): ninho(outro.ninho),p_mundo(outro.p_mundo),n_formigas(outro.n_formigas){
    for(int i=0;i<outro.n_formigas;i++){
        formigueiro.push_back(outro.formigueiro[i]->duplica());
    }
}

Comunidade& Comunidade::operator =(Comunidade outro){
    swap(outro);
    return *this;
}
void Comunidade::swap(Comunidade& outro){
    formigueiro.swap(outro.formigueiro);
    std::swap(p_mundo,outro.p_mundo);
    std::swap(ninho,outro.ninho);
    std::swap(n_formigas,outro.n_formigas);
}
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

bool Comunidade::ckif_formiga_da_mesma_comunidade_num_raio_visao(Ponto local_origem, int raio_visao, Formiga* formiga) const {
    auto it = formigueiro.cbegin();
    while(it != formigueiro.cend()){
        if(formiga->getPonto() == (*it)->getPonto())
            ++it;
        else{
            if((abs(local_origem.getX()-(*it)->getPonto().getX()) <= raio_visao) && (abs(local_origem.getY()-(*it)->getPonto().getY()) <= raio_visao) )
                return true;
        }
        ++it;
    }
}

Ponto Comunidade::local_formiga_a_proteger(int raio, Ponto local_formiga, Formiga* formiga) {
    auto it = formigueiro.cbegin();
    while(it != formigueiro.cend()){
        if(formiga->getPonto() == (*it)->getPonto())
            ++it;
        else{
            if((abs(local_formiga.getX()-(*it)->getPonto().getX()) <= raio) && (abs(local_formiga.getY()-(*it)->getPonto().getY()) <= raio) )
                return (*it)->getPonto();
        }
        ++it;
    }
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
Ponto Comunidade::local_formiga_com_mais_energia(int raio, Ponto local_formiga){
    const Formiga* maux=nullptr;
    auto it = formigueiro.cbegin();
    while(it != formigueiro.cend()){
        if((abs(local_formiga.getX()-(*it)->getPonto().getX())<=raio) && (abs(local_formiga.getY()-(*it)->getPonto().getY())<=raio)){
            if(maux==nullptr)
                maux=(*it);
            else{
                if((*it)->getenergia() > maux->getenergia())
                    maux=(*it);
            }
        }
        ++it;
    }
    return maux->getPonto();
}
int Comunidade::getNinhoId() const{
    return ninho.getId();
}
Ponto Comunidade::getNinhoPonto() const{
    return ninho.getPonto();
}
void Comunidade::setNinhoenerg(float addenerg){
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
bool Comunidade::cria1Formiga(char tipo, int linha, int coluna){
    if(tipo == 'E'){
        formigueiro.push_back(new FExploradora(linha, coluna, ++n_formigas, &ninho));
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
bool Comunidade::addenergFormiga(int linha, int coluna, float energ){
    Ponto aux(linha, coluna);
    auto it = formigueiro.begin();
    while(it != formigueiro.end()){
        if(aux == (*it)->getPonto()){
            (*it)->modifica_energia(energ);
            return true;
        }
        ++it;
    }
    return false;
}
Ponto Comunidade::getPontoFormiga(int num) const{
    return formigueiro.at(num)->getPonto();
}
char Comunidade::getTipoFormiga(int num) const{
    return formigueiro.at(num)->getTipo();
}
bool Comunidade::mataformiga(int linha, int coluna){
    Ponto aux(linha, coluna);
    auto it= formigueiro.begin();
    while(it != formigueiro.end()){
        if((*it)->getPonto() == aux){
            delete (*it);
            it=formigueiro.erase(it);
            --n_formigas;
            return true;
        }
        ++it;
    }
    return false;
}
Comunidade::~Comunidade() {
    auto it= formigueiro.begin();
    while(it != formigueiro.end()){
        delete (*it);
        it=formigueiro.erase(it);
    }
}

