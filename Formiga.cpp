#include "Formiga.h"
#include "Jogo.h"
#include <sstream>
#include <ctime>
Formiga::Formiga(int linha, int coluna, int id, Ninho* ninho_a_que_pertence): local_f(linha, coluna), energia_f(200), id_f(id), energia_inicial(200), ninho_f(ninho_a_que_pertence){    //ACABAR
}

string Formiga::getInfo() const{
    ostringstream oss;
    oss << "Formiga " << id_f << "->" << "\tLocal: " << local_f.obtemXY() << "\tEnergia: " << energia_f;
    return oss.str();
}

Ponto Formiga::getPonto() const{return local_f;}

void Formiga::iteracao(Jogo* jogo_atual){
    srand (time(NULL));
    int mov,x=local_f.getX(),y=local_f.getY(),auxx,auxy;
    if(ninho_f->getPonto() == local_f){
        if(energia_f>energia_inicial){
            energia_f -= ninho_f->getEnerg_Iter();
            ninho_f->setenergia_n(ninho_f->getEnerg_Iter());                        // REVER TENDO EM CONTA CONCEITO DE ENCAPSULAMENTO
            return;
        }
        if(energia_f < (energia_inicial*0.5)){
            if(ninho_f->setenergia_n(-ninho_f->getEnerg_Iter())){
                energia_f += ninho_f->getEnerg_Iter();
                return;
            }
        }
        do{
            mov = rand() % 4;
            switch(mov){
                case 0:
                    x=local_f.getX()-1;
                    break;
                case 1:
                    y=local_f.getY()-1;
                    break;
                case 2:
                    y=local_f.getY()+1;
                    break;
                case 3:
                    x=local_f.getX()+1;
                    break;
                }
            }while(!jogo_atual->jckif_space_isempty(x,y));
            local_f.setX(x);
            local_f.setY(y);
            return;
    }else{
        do{
            mov = rand() % 4;
            auxx= (rand() % 8)+1;
            auxy= (rand() % 8)+1;
            switch(mov){
                case 0:
                    x=local_f.getX()+auxx;
                    y=local_f.getY()+auxy;
                    break;
                case 1:
                    x=local_f.getX()-auxx;
                    y=local_f.getY()+auxy;
                    break;
                case 2:
                    x=local_f.getX()-auxx;
                    y=local_f.getY()-auxy;
                    break;
                case 3:
                    x=local_f.getX()+auxx;
                    y=local_f.getY()-auxy;
                    break;
                }
            if(ninho_f->getPonto().getX() == x && ninho_f->getPonto().getY()==y)
                break;
        }while(!jogo_atual->jckif_space_isempty(x,y));
        consomeEnergia(auxx+auxy+1);
        local_f.setX(x);
        local_f.setY(y);
    }
}
void Formiga::consomeEnergia(int energia){
    if(energia_f-energia <= 0)
        energia_f=0;
    else
        energia_f-=energia;
}
void Formiga::addenergia(int energia){
    energia_f += energia;
}
Formiga::~Formiga() {
}

