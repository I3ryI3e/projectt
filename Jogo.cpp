#include "Jogo.h"
#include <sstream>
#include <iostream>
#include <fstream>

Jogo::Jogo():limite(-1),energ_init_ninho(-1),def_p_novaformiga(-1),def_energ_iter(1),
            p_init_migalhas(-1),energ_init_migalhas(-1),migalhas_iter(-1){
}

void Jogo::configuracao(){
    string linha,aux;
    fstream file;
    int estado=0;
    do{
        if(estado == 1 || estado == 3){
          //update mapa
            cout << "SIMULACAO" << endl;
        }
        if(estado == 0 || estado == 1){
            getline(cin, linha);
        }else if(file.is_open()){
                getline(file,linha);
                if(file.eof()){
                    file.close();
                    estado -= 2;
                }
            }else{
                istringstream iss(linha);
                iss >> aux >> aux;
                file.open(aux);
                if(file.fail()){
                    cout << "Erro a abrir o ficheiro." << endl;
                    estado -= 2;
                    continue;
                }
                getline(file,linha);
            }
        if(linha.compare("sair") != 0)
            estado=tratacmd(linha,estado);       
        
    }while(linha.compare("sair") != 0);
}

int Jogo::tratacmd(string linha,int estado){
    istringstream iss(linha);
    string aux;
    if(linha.compare("inicio") == 0 && (estado == 0 || estado == 2)){
        if(ckif_notconfig() == false){
            estado += 1;
        }
        return estado;
    }
       
    iss >> aux;
    if(aux.compare("defmundo") == 0 && (estado == 0 || estado == 2)){
        int nlim;
        iss >> nlim;
        if(nlim >= 10 && nlim < 50)
            limite=nlim;
        else
            cout << "Comando nao executado. Limite tem que estar entre 10 e 50." << endl;
        return estado;
    }
    if(aux.compare("defen") == 0){
        int nen;
        iss >> nen;
        if(nen > 0 && nen <= 500)
            energ_init_ninho=nen;
        else
            cout << "Comando nao executado. Energia inicial do ninho tem que estar entre 1 e 500." << endl;
        return estado;
    }
    if(aux.compare("defpc") == 0){
        int npc;
        iss >> npc;
        if(npc >= 0 && npc <= 100)
            def_p_novaformiga=npc;
        else
            cout << "Comando nao executado. Percentagem de energia inicial necessaria para criar uma formiga tem que estar entre 0 e 100." << endl;
        return estado;
    }
    if(aux.compare("defvt") == 0){
        int nvt;
        iss >> nvt;
        if(nvt > 0 && nvt <= 100)
            def_energ_iter=nvt;
        else
            cout << "Comando nao executado. Energia tranferida por iteracao tem que estar entre 1 e 100." << endl;
        return estado;
    }
    if(aux.compare("defmi") == 0){
        int nmi;
        iss >> nmi;
        if(nmi >= 0 && nmi <= 100)
            p_init_migalhas=nmi;
        else
            cout << "Comando nao executado. Percentagem inicial de posicoes vazias que vao ter migalhas tem que estar entre 0 e 100." << endl;
        return estado;
    }
    if(aux.compare("defme") == 0){
        int nme;
        iss >> nme;
        if(nme > 0 && nme <= 250)
            energ_init_migalhas=nme;
        else
            cout << "Comando nao executado. Energia inicial das migalhas tem que estar entre 1 e 250." << endl;
        return estado;
    }
    if(aux.compare("defnm") == 0){
        int nnm;
        iss >> nnm;
        if(nnm >= 0 && nnm <= 500)
            migalhas_iter=nnm;
        else
            cout << "Comando nao executado. Numero maximo de migalhas criadas por iteracao tem que estar entre 0 e 500." << endl;
        return estado;
    }
    if(aux.compare("executa") == 0 && (estado == 0 || estado == 1) ){
        return estado += 2;
    }
    if(aux.compare("ninho") == 0 && (estado == 1 || estado == 3)){
        int lin, col;
        iss >> lin >> col;
        crianinho(lin, col);
        return estado;
    }
    if(aux.compare("lista") == 0 && (estado == 1 || estado == 3)){  ///// Não é um comando que é para fazer depois tem que se mudar
        auto it = comunidades.cbegin();
        while(it != comunidades.cend()){
            cout << it->getInfo() << endl;
            ++it;
        }
        return estado;
    }
    if(aux.compare("criaf") == 0 && (estado == 1 || estado == 3)){
        int num,id_n;
        char tipo;
        bool teste;
        iss >> num >> tipo >> id_n;
        teste=criaformigas(num, tipo, id_n);
        if(teste == false){
            cout << "Erro na criacao das formigas!" << endl;
        }
        return estado;
    }
    if(aux.compare("energninho") == 0 && (estado == 1 || estado == 3)){
        int addenerg, numninho;
        iss >> numninho >> addenerg;
        auto it = comunidades.begin();
        while(it != comunidades.end()){
            if(it->getNinhoId() == numninho){
                it->setNinhoenerg(addenerg);
                return estado;
            }
            ++it;
        }
        return estado;
    }
    return estado;
}

void Jogo::crianinho(int linha, int coluna){
    if(linha < 0 || linha >= limite || coluna < 0 || coluna >= limite){
        return;
    }
    if(jckif_space_isempty(linha, coluna) == false){
        return;
    }
    Comunidade novac(this ,linha, coluna, energ_init_ninho, def_p_novaformiga, def_energ_iter);
    comunidades.push_back(novac);
}

bool Jogo::jckif_space_isempty(int linha, int coluna) const{
    Ponto aux(linha, coluna);
    auto it = comunidades.cbegin();
    while(it != comunidades.cend()){
        if(it->cckif_space_isempty(linha, coluna) == false)
            return false;
        ++it;
    }
    auto iter = migalhas.cbegin();
    while(iter != migalhas.cend()){
        if(aux == iter->getPonto())
            return false;
        ++iter;
    }
    return true;
}

bool Jogo::ckif_notconfig() const{
    ostringstream oss;
    oss << "Os comandos: ";
    if(limite == -1)
        oss << "defmundo, ";
    if(energ_init_ninho == -1)
        oss << "defen, ";
    if(def_p_novaformiga == -1)
        oss << "defpc, ";
    if(p_init_migalhas == -1)
        oss << "defmi, ";
    if(energ_init_migalhas == -1)
        oss << "defme, ";
    if(migalhas_iter == -1)
        oss << "defnm, ";
    if(!oss.str().compare("Os comandos: "))
       return false;
    else{
        oss << "nao foram corretamente inicializados.";
        cout << oss.str() << endl;
        return true;
    }
}

bool Jogo::criaformigas(int quantas, char tipo, int id_n){
    auto it = comunidades.begin();
    bool teste;
    while(it != comunidades.end()){
        if(it->getNinhoId() == id_n){
            teste=it->criaFormigas(quantas,tipo);
            return teste;
        }
        it++;
    }
    return false;
}

int Jogo::getLimite() const{
    return limite;
}

Jogo::Jogo(const Jogo& orig) {
}

Jogo::~Jogo() {
}

