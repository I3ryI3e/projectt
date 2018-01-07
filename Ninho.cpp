#include "Ninho.h"
#include "Comunidade.h"
#include "Formiga.h"
#include <sstream>
#include <ctime>

int Ninho::n_ninhos = 0;

Ninho::Ninho(int linha, int coluna, float energ_init_ninho, int def_p_novaformiga, int def_energ_iter): local_n(linha, coluna),
        energia_n(energ_init_ninho), p_novaformiga(def_p_novaformiga), energ_iter(def_energ_iter), id_n(++n_ninhos), energia_inicial(energ_init_ninho){}
void Ninho::resetN_Ninhos(){
    n_ninhos=0;
}

Ponto Ninho::getPonto() const{return local_n;}

string Ninho::getInfo() const{
    ostringstream oss;
    oss << "Ninho " << id_n << "->\t" << "Local: " << local_n.obtemXY() << "\tEnergia: " << energia_n << endl;
    return oss.str();
}

int Ninho::getId() const{return id_n;}

bool Ninho::setenergia_n(float addenerg){
    if(energia_n + addenerg > 0){
        energia_n += addenerg;
        return true;
    }
    return false;
}

float Ninho::get_energy_from_formiga() {
    energia_n+=energ_iter;
    return energ_iter;
}

float Ninho::give_energy_to_formiga() {
    float aux;
    if(energia_n<=1)
        return 0;
    else if(energia_n-energ_iter <1){
        aux = energia_n-1;
        energia_n=1;
        return aux;
    }else{
        energia_n-=energ_iter;
        return energ_iter;
    }      
}

int Ninho::getEnerg_Iter() const{return energ_iter;}

float Ninho::getEnergy() const { return energia_n;}


void Ninho::iteracao(Comunidade* sua_Comunidade){
    srand(time(NULL));
    if(sua_Comunidade->ckif_formigas_no_ninho())
        return;
    if(energia_n >= energia_inicial+(energia_inicial*((float)p_novaformiga/100))){
        float aux=sua_Comunidade->born_new_formiga_in_ninho();
        energia_n-=aux;
    }
}

void Ninho::set_def_energ_iter(int novo_valor) {energ_iter = novo_valor;}

void Ninho::set_def_p_novaformiga(int novo_valor) {p_novaformiga = novo_valor;}

Ninho::~Ninho() {}

