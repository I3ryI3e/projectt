#include "Comunidade.h"
#include "Ponto.h"
#include "Formiga.h"
#include "Mundo.h"
#include "FExploradora.h"
#include "FVigilante.h"
#include "FAssaltante.h"
#include "FCuidadora.h"
#include "FSuperman.h"
#include <sstream>
#include <random>
#include <ctime>
#include <cstdlib>

Comunidade::Comunidade(Mundo* principal, int linha, int coluna, float energ_init_ninho, int def_p_novaformiga, int def_energ_iter): p_mundo(principal), ninho(linha, coluna,
        energ_init_ninho, def_p_novaformiga, def_energ_iter), n_formigas(0), contador_formigas(0){
}

Comunidade::Comunidade(const Comunidade& outro): ninho(outro.ninho), p_mundo(outro.p_mundo), n_formigas(outro.n_formigas), contador_formigas(outro.contador_formigas){
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
    std::swap(contador_formigas, outro.contador_formigas);
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

Ninho* Comunidade::getNinho() {
    return &ninho;
}

void Comunidade::remove_Dead_Formigas() {
    auto it=formigueiro.begin();
    while(it != formigueiro.end()){
        if((*it)->getenergia() <= 0){
            delete (*it);
            it=formigueiro.erase(it);
            --n_formigas;
        }else
            ++it;
    }
}


void Comunidade::setMundo(Mundo* mundo) {
    p_mundo=mundo;
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

bool Comunidade::ckif_formigas_no_raio(Ponto local_origem, int raio) const {
    auto it = formigueiro.cbegin();
    while(it != formigueiro.cend()){
        if((*it)->getPonto() == ninho.getPonto())
            ++it;
        else
            if((abs(local_origem.getX()-(*it)->getPonto().getX()) <= raio) && (abs(local_origem.getY()-(*it)->getPonto().getY()) <= raio) && (*it)->getenergia()>0 )
                return true;
        ++it;
    }
    return false;
}

bool Comunidade::ckif_formiga_da_mesma_comunidade_num_raio_visao(Ponto local_origem, int raio_visao) const {
    auto it = formigueiro.cbegin();
    while(it != formigueiro.cend()){
        if(local_origem == (*it)->getPonto() || ninho.getPonto() == (*it)->getPonto())
            ++it;
        else{
            if((abs(local_origem.getX()-(*it)->getPonto().getX()) <= raio_visao) && (abs(local_origem.getY()-(*it)->getPonto().getY()) <= raio_visao) && (*it)->getenergia()>0)
                return true;
            ++it;
        }

    }
    return false;
}

Ponto Comunidade::local_formiga_mesma_comunidade_com_menos_energia(Ponto local_formiga) const{
    Ponto aux(-1,-1);
    float energaux=0;
    auto it = formigueiro.cbegin();
    while(it != formigueiro.cend()){
        if(local_formiga == (*it)->getPonto() || ninho.getPonto() == (*it)->getPonto())
            ++it;
        else{
            if(energaux == 0){
                energaux = (*it)->getenergia();
                aux = (*it)->getPonto();
            }else{
                if(energaux > (*it)->getenergia()){
                    energaux = (*it)->getenergia();
                    aux = (*it)->getPonto();
                }
            }
            ++it;
        }
    }
    return aux;
}

Ponto Comunidade::local_formiga_a_proteger(int raio, Ponto local_formiga) const{
    Ponto aux(-1,-1);
    auto it = formigueiro.cbegin();
    while(it != formigueiro.cend()){
        if(local_formiga == (*it)->getPonto() || ninho.getPonto() == (*it)->getPonto())
            ++it;
        else{
            if((abs(local_formiga.getX()-(*it)->getPonto().getX()) <= raio) && (abs(local_formiga.getY()-(*it)->getPonto().getY()) <= raio) && (*it)->getenergia()>0 )
                return (*it)->getPonto();
            ++it;
        }
    }
    return aux;
}

int Comunidade::ckif_formiga_num_raio_visao_quadrante(Ponto local_origem, int raio_visao, int formiga_x) const {
    int auxx,auxy;
    if(ninho.getPonto() == formigueiro.at(formiga_x)->getPonto())
        return -1;
    if((abs(local_origem.getX()-(formigueiro.at(formiga_x)->getPonto().getX())) <= raio_visao) && (abs(local_origem.getY()-(formigueiro.at(formiga_x)->getPonto().getY()))<=raio_visao) && formigueiro.at(formiga_x)->getenergia()>0){
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

bool Comunidade::ckif_formigas_no_ninho() const {
    auto it=formigueiro.cbegin();
    while(it != formigueiro.cend()){
        if((*it)->getPonto() == ninho.getPonto())
            return true;
        ++it;
    }
    return false;
}

Ponto Comunidade::local_formiga_com_mais_energia(int raio, Ponto local_formiga) const{
    Ponto aux(-1,-1);
    float energaux=0;
    auto it = formigueiro.cbegin();
    while(it != formigueiro.cend()){
        if((abs(local_formiga.getX()-(*it)->getPonto().getX())<=raio) && (abs(local_formiga.getY()-(*it)->getPonto().getY())<=raio) && (*it)->getenergia()>0){
            if(energaux == 0){
                energaux = (*it)->getenergia();
                aux = (*it)->getPonto();
            }else{
                if(energaux < (*it)->getenergia()){
                    energaux = (*it)->getenergia();
                    aux = (*it)->getPonto();
                }
            }
        }
        ++it;
    }
    return aux;
}

int Comunidade::getNinhoId() const{return ninho.getId();}

Ponto Comunidade::getNinhoPonto() const{return ninho.getPonto();}

void Comunidade::setNinhoenerg(float addenerg){ninho.setenergia_n(addenerg);}

bool Comunidade::criaFormigas(int quantas, char tipo){
    srand (time(NULL));
    switch(tipo){
        case 'E' : 
            for(int i=0;i<quantas;i++){
                int r_linha, r_coluna;
                do{
                    r_linha= rand() % p_mundo->getLimite();
                    r_coluna= rand() % p_mundo->getLimite();
                }while(p_mundo->mckif_space_isempty(r_linha,r_coluna) == false);
                formigueiro.push_back(new FExploradora(r_linha,r_coluna,++contador_formigas,&ninho));
                ++n_formigas;
            }
            return true;
        case 'C' :
            for(int i=0;i<quantas;i++){
                int r_linha, r_coluna;
                do{
                    r_linha= rand() % p_mundo->getLimite();
                    r_coluna= rand() % p_mundo->getLimite();
                }while(p_mundo->mckif_space_isempty(r_linha,r_coluna) == false);
                formigueiro.push_back(new FCuidadora(r_linha,r_coluna,++contador_formigas,&ninho));
                ++n_formigas;
            }
            return true;
        case 'V' :
            for(int i=0;i<quantas;i++){
                int r_linha, r_coluna;
                do{
                    r_linha= rand() % p_mundo->getLimite();
                    r_coluna= rand() % p_mundo->getLimite();
                }while(p_mundo->mckif_space_isempty(r_linha,r_coluna) == false);
                formigueiro.push_back(new FVigilante(r_linha,r_coluna,++contador_formigas,&ninho));
                ++n_formigas;
            }
            return true;
        case 'A' :
            for(int i=0;i<quantas;i++){
                int r_linha, r_coluna;
                do{
                    r_linha= rand() % p_mundo->getLimite();
                    r_coluna= rand() % p_mundo->getLimite();
                }while(p_mundo->mckif_space_isempty(r_linha,r_coluna) == false);
                formigueiro.push_back(new FAssaltante(r_linha,r_coluna,++contador_formigas,&ninho));
                ++n_formigas;
            }
            return true;
        case 'S' :
            for(int i=0;i<quantas;i++){
                int r_linha, r_coluna;
                do{
                    r_linha= rand() % p_mundo->getLimite();
                    r_coluna= rand() % p_mundo->getLimite();
                }while(p_mundo->mckif_space_isempty(r_linha,r_coluna) == false);
                formigueiro.push_back(new FSuperman(r_linha,r_coluna,++contador_formigas,&ninho));
                ++n_formigas;
            }
            return true;
    }
    return false;
}

float Comunidade::born_new_formiga_in_ninho() {
    int i=rand()%5;
    switch(i){
        case 0:
            if(ninho.getEnergy()>201)
                cria1Formiga('E',ninho.getPonto().getX(),ninho.getPonto().getY());
            return 200;
        case 1:
            if(ninho.getEnergy()>101)
                cria1Formiga('C',ninho.getPonto().getX(),ninho.getPonto().getY());
            return 100;
        case 2:
            if(ninho.getEnergy()>151)
                cria1Formiga('V',ninho.getPonto().getX(),ninho.getPonto().getY());
            return 150;
        case 3:
            if(ninho.getEnergy()>81)
                cria1Formiga('A',ninho.getPonto().getX(),ninho.getPonto().getY());
            return 80;
        case 4:
            if(ninho.getEnergy()>201)
                cria1Formiga('S',ninho.getPonto().getX(),ninho.getPonto().getY());
            return 200;
    }
}

bool Comunidade::cria1Formiga(char tipo, int linha, int coluna){
    switch(tipo){
        case 'E':
            formigueiro.push_back(new FExploradora(linha, coluna, ++contador_formigas, &ninho));
            ++n_formigas;
            return true;  
        case 'C' :
            formigueiro.push_back(new FCuidadora(linha, coluna, ++contador_formigas, &ninho));
            ++n_formigas;
            return true;
        case 'V' :
            formigueiro.push_back(new FVigilante(linha, coluna, ++contador_formigas, &ninho));
            ++n_formigas;
            return true;
        case 'A' : 
            formigueiro.push_back(new FAssaltante(linha, coluna, ++contador_formigas, &ninho));
            ++n_formigas;
            return true;
        case 'S' :
            formigueiro.push_back(new FSuperman(linha, coluna, ++contador_formigas, &ninho));
            ++n_formigas;
            return true;
    }
    return false;
}

void Comunidade::iteracao(){
    auto it= formigueiro.begin();
    while(it != formigueiro.end()){
        (*it)->iteracao(p_mundo, this);
        ++it;
    }
    ninho.iteracao(this);
}

int Comunidade::getNFormigas() const{return n_formigas;}

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

float Comunidade::formiga_gives_energy_to_ninho() {
    return ninho.get_energy_from_formiga();
}

float Comunidade::formiga_try_to_take_energy_from_ninho() {
    return ninho.give_energy_to_formiga();
}


Ponto Comunidade::getPontoFormiga(int num) const{return formigueiro.at(num)->getPonto();}

char Comunidade::getTipoFormiga(int num) const{return formigueiro.at(num)->getTipo();}

float Comunidade::try_totake_EnergiaFormiga(Ponto aux){
    auto it= formigueiro.begin();
    while(it != formigueiro.end()){
        if((*it)->getPonto() == aux){
            float auxf = ((*it)->getenergia()/2);
            (*it)->modifica_energia(-auxf);
            return (auxf);
        }
        ++it;
    }
    return -1;
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

void Comunidade::ninho_set_def_energ_iter(int novo_valor) {ninho.set_def_energ_iter(novo_valor);}

void Comunidade::ninho_set_def_p_novaformiga(int novo_valor) {ninho.set_def_p_novaformiga(novo_valor);}

Comunidade::~Comunidade() {
    auto it= formigueiro.begin();
    while(it != formigueiro.end()){
        delete (*it);
        it=formigueiro.erase(it);
    }
}

