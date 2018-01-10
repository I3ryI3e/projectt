#include "Formiga.h"
#include "Mundo.h"
#include "FAssaltante.h"
#include <sstream>

Formiga::Formiga(int linha, int coluna, float energ, int id, int rvis, int rmov, Ninho* ninho_a_que_pertence): local_f(linha, coluna),
        energia_f(energ),energia_init(energ),id_f(id), raio_visao(rvis), raio_movimento(rmov), ninho_f(ninho_a_que_pertence), n_iteracoes_sem_ir_ao_ninho(0){}

Formiga::Formiga(const Formiga& outro): local_f(outro.local_f), energia_f(outro.energia_f), id_f(outro.id_f), raio_visao(outro.raio_visao), raio_movimento(outro.raio_movimento), ninho_f(outro.ninho_f){
    for(int i=0; i<outro.comportamento.size();i++){
        comportamento.push_back(outro.comportamento[i]->duplica());
    }
}

Formiga& Formiga::operator =(Formiga& outro){
    local_f=outro.local_f;
    energia_f=outro.energia_f;
    raio_movimento=outro.raio_movimento;
    raio_visao=outro.raio_visao;
    ninho_f=outro.ninho_f;
    id_f=outro.id_f;
    auto it = comportamento.begin();
    while(it != comportamento.end()){
        delete (*it);
        ++it;
    }
    comportamento.clear();
    auto iter = outro.comportamento.cbegin();
    while(iter != outro.comportamento.cend()){
        comportamento.push_back((*iter)->duplica());
        ++iter;
    }
}

string Formiga::getInfo() const{
    ostringstream oss;
    oss << "Formiga " << id_f << "->" << "\tLocal: " << local_f.obtemXY() << "\tEnergia: " << energia_f << "\tTipo: " << getTipo();
    return oss.str();
}

int Formiga::getNIteracoesSemNinho() const{ return n_iteracoes_sem_ir_ao_ninho;}

Ponto Formiga::getPonto() const{return local_f;}

int Formiga::getRaioVisao() const{return raio_visao;}

float Formiga::getenergia() const{return energia_f;}

void Formiga::resetNIteracoesSemNinho() {n_iteracoes_sem_ir_ao_ninho=-1;}

bool Formiga::ckif_ninho_in_raio_visao() {
    if((abs(ninho_f->getPonto().getX()-local_f.getX()) <= raio_visao) && (abs(ninho_f->getPonto().getY()-local_f.getY()) <= raio_visao))
        return true;
    return false;
}

void Formiga::iteracao(Mundo* mundo_atual, Comunidade* comunidade){
    float aux;
    if(local_f == ninho_f->getPonto()){
        if((energia_f >= energia_init*0.5) && (energia_f<=energia_init)){
            get_out_of_ninho(mundo_atual);
        }else if(energia_f > energia_init){
            aux=comunidade->formiga_gives_energy_to_ninho();
            energia_f-=aux;
        }else{
            if((aux=comunidade->formiga_try_to_take_energy_from_ninho()) == 0){
                get_out_of_ninho(mundo_atual);
            }else
                energia_f+=aux;     
        }
        n_iteracoes_sem_ir_ao_ninho=0;
        return;
    }
    auto it =comportamento.begin();
    while(it != comportamento.end()){
        if((*it)->condicao(this, mundo_atual, comunidade)){
            (*it)->accao(this, mundo_atual, comunidade);
            it=comportamento.end();
        }else
            ++it;
    }
    ++n_iteracoes_sem_ir_ao_ninho;
}

void Formiga::get_out_of_ninho(Mundo* mundo) {
    for(int k=0;k<10;k++){
        for(int i=-1-k;i<2+k;i++){
            for(int j=-1-k;j<2+k;j++){
                if(mundo->mckif_noants_nonest(local_f.getX()+i, local_f.getY()+j)){
                    local_f.setX(local_f.getX()+i);
                    local_f.setY(local_f.getY()+j);
                    return;
                }
            }
        }
    }
}


int Formiga::getRaioMovimento() const{return raio_movimento;}

bool Formiga::moveFormiga(int x, int y, Mundo* mundo){
    if(local_f.getX()+x >= mundo->getLimite() || local_f.getY()+y >= mundo->getLimite() || local_f.getX()+x<0 || local_f.getY()+y<0)
        return false;
    if(abs(x) > raio_movimento || abs(y) > raio_movimento)
        return false;
    if(x==0 && y==0){
        consomeEnergia(0);
        return true;
    }
    if((((local_f.getX()+x) == ninho_f->getPonto().getX()) && ((local_f.getY()+y) == ninho_f->getPonto().getY()))){
        local_f.setX(local_f.getX()+x);
        local_f.setY(local_f.getY()+y);
        consomeEnergia((abs(x)+abs(y)));
        return true;
    }
    if(mundo->mckif_noants_nonest((local_f.getX()+x), (local_f.getY()+y))){
        local_f.setX(local_f.getX()+x);
        local_f.setY(local_f.getY()+y);
        consomeEnergia((abs(x)+abs(y)));
        return true;
    } else{
        return false;
    }
}

void Formiga::addRegra(Regra* nregra){comportamento.push_back(nregra);}

void Formiga::modifica_energia(float energia){energia_f += energia;}

bool Formiga::mov_SuperFormiga(int linha, int coluna, Mundo* mundo){
    if(linha >= mundo->getLimite() || coluna >= mundo->getLimite() || linha<0 || coluna<0)
        return false;
    local_f.setX(linha);
    local_f.setY(coluna);
    return true;
}

Formiga::~Formiga() {
    auto it = comportamento.begin();
    while(it != comportamento.end()){
        delete (*it);
        it++;
    }
    comportamento.clear();
}

