#include "Mundo.h"
#include <sstream>
#include <iostream>
#include <fstream>

Mundo::Mundo():limite(-1),energ_init_ninho(-1),def_p_novaformiga(-1),def_energ_iter(1),
            p_init_migalhas(-1),energ_init_migalhas(-1),migalhas_iter(-1){
}

void Mundo::configuracao(){
    string linha,aux;
    fstream file;
    int estado=0;
    Interface::initial_screen();
    do{
        if(estado == 1 || estado == 3){
            updatemap();
        }else{
            Interface::screen_config_stage();        //AS MENSAGENS DE ERRO TAO MAL AGORA
        }
        if(estado == 0 || estado == 1){
            linha = Interface::getlinha();
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

int Mundo::tratacmd(string linha,int estado){
    istringstream iss(linha);
    ostringstream oss;
    string aux;
    if(linha.compare("inicio") == 0 && (estado == 0 || estado == 2)){
        if(ckif_notconfig() == false){
            estado += 1;
            Interface::clrscreen();
        }
        return estado;
    }
    iss >> aux;
    if(aux.compare("defmundo") == 0 && (estado == 0 || estado == 2)){
        int nlim;
        iss >> nlim;
        if(nlim >= 10 && nlim < 50)
            limite=nlim;
        return estado;
    }
    if(aux.compare("defen") == 0){
        int nen;
        iss >> nen;
        if(nen > 0 && nen <= 500)
            energ_init_ninho=nen;
        return estado;
    }
    if(aux.compare("defpc") == 0){
        int npc;
        iss >> npc;
        if(npc >= 0 && npc <= 100)
            def_p_novaformiga=npc;
        return estado;
    }
    if(aux.compare("defvt") == 0){
        int nvt;
        iss >> nvt;
        if(nvt > 0 && nvt <= 100)
            def_energ_iter=nvt;
        return estado;
    }
    if(aux.compare("defmi") == 0){
        int nmi;
        iss >> nmi;
        if(nmi >= 0 && nmi <= 100)
            p_init_migalhas=nmi;
        return estado;
    }
    if(aux.compare("defme") == 0){
        int nme;
        iss >> nme;
        if(nme > 0 && nme <= 250)
            energ_init_migalhas=nme;
        return estado;
    }
    if(aux.compare("defnm") == 0){
        int nnm;
        iss >> nnm;
        if(nnm >= 0 && nnm <= 500)
            migalhas_iter=nnm;
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
    if(aux.compare("listamundo") == 0 && (estado == 1 || estado == 3)){
        auto it = comunidades.cbegin();
        while(it != comunidades.cend()){
            oss << it->getInfoGeral() << endl;
            ++it;
        }
        auto iter = migalhas.cbegin();
        oss << "Migalhas:" << endl;
        while(iter != migalhas.cend()){
            oss << iter->getInfo() << endl;
            ++iter;
        }
        Interface::mostrainfo(oss.str());
        return estado;
    }
    if(aux.compare("listaninho") == 0 && (estado == 1 || estado == 3)){
        int nninho;
        iss >> nninho;
        auto it = comunidades.cbegin();
        while(it != comunidades.cend()){
            if(nninho == it->getNinhoId()){
                oss << it->getInfoNinho() << endl;
                return estado;
            }
            ++it;
        }
        Interface::mostrainfo(oss.str());
        return estado;
    }
    if(aux.compare("listaposicao") == 0 && (estado == 1 || estado == 3)){
        int lin, col;
        iss >> lin >> col;
        Ponto auxP(lin,col);
        auto it = comunidades.cbegin();
        while(it != comunidades.cend()){
            oss << it->ckwhoisthere(auxP);
            ++it;
        }
        auto iter = migalhas.cbegin();
        while(iter != migalhas.cend()){
            if(iter->getPonto() == auxP)
                oss << iter->getInfo();
            ++iter;
        }
        Interface::mostrainfo(oss.str());
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
    if(aux.compare("migalha") == 0 && (estado == 1 || estado == 3)){
        int lin, col;
        iss >> lin >> col;
        criamigalha(lin, col);
        return estado;
    }
    if(aux.compare("tempo") == 0 && (estado == 1 || estado == 3)){
        if(iss.eof()){
            auto it=comunidades.begin();
            while(it != comunidades.end()){
                it->iteracao();
                ++it;
            }
            auto iter=migalhas.begin();
            while(iter != migalhas.end()){
                iter->iteracao();
                ++iter;
            }
        }else{
            int i;
            vector<Comunidade>::iterator it;
            vector<Migalha>::iterator iter;
            iss >> i;
            for(;i>0;i--){
                it=comunidades.begin();
                while(it != comunidades.end()){
                    it->iteracao();
                    ++it;
                }
                iter=migalhas.begin();
                while(iter != migalhas.end()){
                    iter->iteracao();
                    ++iter;
                }
            }
        }
        return estado;
    }
    if(aux.compare("energformiga") == 0 && (estado == 1 || estado == 3)){
        int lin, col, addenerg;
        iss >> lin >> col >> addenerg;
        auto it = comunidades.begin();
        while(it != comunidades.end()){
            it->addenergFormiga(lin, col, addenerg);
            ++it;
        }
        return estado;
    }
    return estado;
}

void Mundo::criamigalha(int linha, int coluna){
    if(linha < 0 || linha >= limite || coluna < 0 || coluna >= limite){
        return;
    }
    if(mckif_space_isempty(linha, coluna) == false){
        return;
    }
    Migalha novam(linha, coluna, energ_init_migalhas);
    migalhas.push_back(novam);
}

void Mundo::crianinho(int linha, int coluna){
    if(linha < 0 || linha >= limite || coluna < 0 || coluna >= limite){
        return;
    }
    if(mckif_space_isempty(linha, coluna) == false){
        return;
    }
    Comunidade novac(this, linha, coluna, energ_init_ninho, def_p_novaformiga, def_energ_iter);
    comunidades.push_back(novac);
}

bool Mundo::mckif_space_isempty(int linha, int coluna) const{
    if(linha < 0 || linha >=limite || coluna < 0 || coluna >=limite)
        return false;
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

bool Mundo::ckif_formigas_no_raio_visao(Comunidade* comunidade, int raio_de_visao, Ponto local_formiga){
    auto it = comunidades.cbegin();
    while(it != comunidades.cend()){
        if(&(*it) == comunidade){
            ++it;
        }else{
            if(it->ckif_formigas_num_raio_visao(local_formiga,raio_de_visao))
                return true;
            ++it;
        }
    }
    return false;
}

bool Mundo::ckif_notconfig() const{
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
        Interface::mostrainfo(oss.str());
        return true;
    }
}

bool Mundo::criaformigas(int quantas, char tipo, int id_n){
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

int Mundo::getLimite() const{
    return limite;
}

void Mundo::updatemap(){
    int i, j;
    Ponto aux(0,0);
    Interface::printborders(limite);
    for(i=0;i<comunidades.size();i++){
        aux = comunidades[i].getNinhoPonto();
        Interface::printcaracter(aux, i, 78, limite);
        for(j=0;j<comunidades[i].getNFormigas();j++){
            aux=comunidades[i].getPontoFormiga(j);
            Interface::printcaracter(aux, i, 190, limite);
        }
    }
    for(i=0;i<migalhas.size();i++){
        aux = migalhas[i].getPonto();
        Interface::printcaracter(aux, 11, 254, limite);
    }
}

Mundo::Mundo(const Mundo& orig) {
}

Mundo::~Mundo() {
}

