#include "Jogo.h"
#include <sstream>
#include <iostream>
#include <fstream>

Jogo::Jogo():limite(-1),energ_init_ninho(-1),def_p_novaformiga(-1),def_energ_iter(1),
            p_init_migalhas(-1),energ_init_migalhas(-1),migalhas_iter(-1){
}

void Jogo::configuracao(){
    string linha;
    do{
        do{
        getline(cin,linha);
        tratacmd(linha, 0);
        }while(linha.compare("inicio"));
    }while(!checkconfig());
}
void Jogo::tratacmd(string linha,int estado){
    istringstream iss(linha);
    string aux;
    if(!linha.compare("inicio"))
        return;
    iss >> aux;
    if(!aux.compare("defmundo")){
        int nlim;
        iss >> nlim;
        if(nlim >= 10 && nlim <50)
            limite=nlim;
        else
            cout << "Comando nao executado. Limite tem que estar entre 10 e 50." << endl;
        return;
    }
    if(!aux.compare("defen")){
        int nen;
        iss >> nen;
        if(nen > 0 && nen <= 500)
            energ_init_ninho=nen;
        else
            cout << "Comando nao executado. Energia inicial do ninho tem que estar entre 1 e 500." << endl;
        return;
    }
    if(!aux.compare("defpc")){
        int npc;
        iss >> npc;
        if(npc >= 0 && npc <= 100)
            def_p_novaformiga=npc;
        else
            cout << "Comando nao executado. Percentagem de energia inicial necessaria para criar uma formiga tem que estar entre 0 e 100." << endl;
        return;
    }
    if(!aux.compare("defvt")){
        int nvt;
        iss >> nvt;
        if(nvt > 0 && nvt <= 100)
            def_energ_iter=nvt;
        else
            cout << "Comando nao executado. Energia tranferida por iteracao tem que estar entre 1 e 100." << endl;
        return;
    }
    if(!aux.compare("defmi")){
        int nmi;
        iss >> nmi;
        if(nmi >= 0 && nmi <= 100)
            p_init_migalhas=nmi;
        else
            cout << "Comando nao executado. Percentagem inicial de posicoes vazias que vao ter migalhas tem que estar entre 0 e 100." << endl;
        return;
    }
    if(!aux.compare("defme")){
        int nme;
        iss >> nme;
        if(nme > 0 && nme <= 250)
            energ_init_migalhas=nme;
        else
            cout << "Comando nao executado. Energia inicial das migalhas tem que estar entre 1 e 250." << endl;
        return;
    }
    if(!aux.compare("defnm")){
        int nnm;
        iss >> nnm;
        if(nnm >= 0 && nnm <= 500)
            migalhas_iter=nnm;
        else
            cout << "Comando nao executado. Numero maximo de migalhas criadas por iteracao tem que estar entre 0 e 500." << endl;
        return;
    }
    if(!aux.compare("executa")){
        string nomefich;
        iss >> nomefich;
        trataficheiro(nomefich);
        return;
    }
}

void Jogo::trataficheiro(string ficheiro, int estado){
    ifstream file;
    string linha;
    file.open(ficheiro);
    if(file.fail()){
        cout << "Erro a abrir o ficheiro." << endl;
        return;
    }
    while(getline(file,linha)){
        //??tratacmd(linha,2+estado);
    }
    
}

bool Jogo::checkconfig() const{
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
       return true;
    else{
        oss << "nao foram corretamente inicializados.";
        cout << oss.str() << endl;
        return false;
    }
}
Jogo::Jogo(const Jogo& orig) {
}

Jogo::~Jogo() {
}

