#include "Mundo.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <ctime>

Mundo::Mundo():pfoca(0,0), limite(-1),energ_init_ninho(-1),def_p_novaformiga(-1),def_energ_iter(1),
            p_init_migalhas(-1),energ_init_migalhas(-1),migalhas_iter(-1), janela(25){
}

void Mundo::configuracao(){
    string linha, aux;
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
                    Interface::mostrainfo("\n\t\t    Erro a abrir o ficheiro.");  //MUDAR
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
            migalhas_iniciais();
        }
        return estado;
    }
    iss >> aux;
    if(aux.compare("defmundo") == 0 && (estado == 0 || estado == 2)){
        int nlim;
        iss >> nlim;
        if(nlim >= 10 && nlim < 100)
            if(nlim < 25)
                janela=nlim;
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
        oss << "Migalhas(" << migalhas.size() << "):" << endl;
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
                it = comunidades.cend();
            }else
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
        bool aux;
        iss >> num >> tipo >> id_n;
        aux=criaformigas(num, tipo, id_n);
        if(aux == false){
            Interface::mostrainfo("Erro na criacao das formigas!");
        }
        return estado;
    }
    if(aux.compare("cria1") == 0 && (estado == 1 || estado == 3)){
        int id_n, lin, col;
        char tipo;
        bool aux;
        iss >> tipo >> id_n >> lin >> col;
        if(lin < 0 || col < 0 || lin >= limite || col >= limite)
            return estado;
        aux=cria1formiga(tipo, id_n, lin, col);
        if(aux == false){
            Interface::mostrainfo("Erro na criacao da formiga!");
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
        if(lin < 0 || col < 0 || lin >= limite || col >= limite)
            return estado;
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
            //novas_migalhas_iter();
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
                //novas_migalhas_iter();
            }
        }
        return estado;
    }
    if(aux.compare("energformiga") == 0 && (estado == 1 || estado == 3)){
        int lin, col;
        float addenerg;
        iss >> lin >> col >> addenerg;
        auto it = comunidades.begin();
        while(it != comunidades.end()){
            if(it->addenergFormiga(lin, col, addenerg))
                return estado;
            ++it;
        }
        return estado;
    }
    if(aux.compare("mata") == 0 && (estado == 1 || estado == 3)){
        int lin, col;
        iss >> lin >> col;
        auto it = comunidades.begin();
        while(it != comunidades.end()){
            if(it->mataformiga(lin, col))
                ;
            else{
            ++it;}
        }
        return estado;
    }
    if(aux.compare("inseticida") == 0 && (estado == 1 || estado == 3)){
        int idn;
        iss >> idn;
        auto it = comunidades.begin();
        while(it != comunidades.end()){
            if(it->getNinhoId() == idn){
                it = comunidades.erase(it);
                return estado;
            }
            ++it;
        }
        return estado;
    }
    if(aux.compare("foca") == 0 && (estado == 1 || estado == 3)){
        int lin, col;
        iss >> lin >> col;
        if(lin < 0 || col < 0 || lin >= limite || col >= limite)
            return estado;
        if(lin-(janela/2) > 0)
            if(lin+(janela/2) < limite)
                lin-=(janela/2);
            else
                lin=limite-(janela);
        else
            lin=0;
        if(col-(janela/2) > 0)
            if(col+(janela/2) < limite)
                col-=(janela/2);
            else
                col=limite-(janela);
        else
            col=0;
        pfoca.setX(lin);
        pfoca.setY(col);
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
    if(mckif_noants_nonest(linha,coluna) == false)
        return false;
    auto iter = migalhas.cbegin();
    while(iter != migalhas.cend()){
        if(aux == iter->getPonto())
            return false;
        ++iter;
    }
    return true;
}

bool Mundo::mckif_noants_nonest(int linha,int coluna)const{
    auto it = comunidades.cbegin();
    while(it != comunidades.cend()){
        if(it->cckif_space_isempty(linha, coluna) == false)
            return false;
        ++it;
    }
    return true;
}

bool Mundo::ckif_formigas_no_raio(Comunidade* comunidade, int raio, Ponto local_formiga) const{
    auto it = comunidades.cbegin();
    while(it != comunidades.cend()){
        if( it->getNinhoId() == comunidade->getNinhoId()){
            ++it;
        }else{
            if(it->ckif_formigas_no_raio(local_formiga,raio))
                return true;
            ++it;
        }
    }
    return false;
}

bool Mundo::ckif_migalhas_no_raio_visao(int raio_de_visao, Ponto local_formiga) const{
    auto it = migalhas.cbegin();
    while(it != migalhas.cend()){
        if((abs(local_formiga.getX()-it->getPonto().getX())<=raio_de_visao) && (abs(local_formiga.getY()-it->getPonto().getY())<=raio_de_visao)){
            return true;
        }
        ++it;
    }
    return false;
}

bool Mundo::ckif_migalha_adjacente(Ponto local_formiga)const{
    auto it=migalhas.cbegin();
    while(it != migalhas.end()){
        if(abs(it->getPonto().getX() - local_formiga.getX()) <= 1 && abs(it->getPonto().getY() - local_formiga.getY()) <= 1)
            return true;
        ++it;
    }
}

float Mundo::try_to_get_energy_from_migalha(Ponto aux, float percentage) {
    int auxnum;
    auto it=migalhas.begin();
    while(it != migalhas.end()){
        if(it->getPonto()==aux){
            auxnum=it->loseEnergy(percentage);
            return auxnum;
        }
        ++it;
    }
    return 0;
}

float Mundo::try_to_get_energy_from_formiga(Ponto aux){
    float auxf;
    auto it = comunidades.begin();
    while(it != comunidades.end()){
        if((auxf = it->try_totake_EnergiaFormiga(aux)) != -1)
            return auxf;
        ++it;
    }
    return -1;
}

Ponto Mundo::local_migalha_com_mais_energia(int raio_de_visao, Ponto local_formiga){
    const Migalha* maux=nullptr;
    auto it = migalhas.cbegin();
    while(it != migalhas.cend()){
        if((abs(local_formiga.getX()-it->getPonto().getX())<=raio_de_visao) && (abs(local_formiga.getY()-it->getPonto().getY())<=raio_de_visao)){
            if(maux==nullptr)
                maux= &(*it);
            else{
                if(it->getEnergia() > maux->getEnergia())
                    maux=&(*it);
            }
        }
        ++it;
    }
    return maux->getPonto();
}

Ponto Mundo::local_formiga_enemy(int raio, Ponto local_formiga, Comunidade* comunidade) {
    auto it= comunidades.cbegin();
    while(it != comunidades.cend()){
        if(comunidade->getNinhoId() == it->getNinhoId())
            ++it;
        else{
            if(it->ckif_formigas_no_raio(local_formiga,raio))
                return it->local_formiga_com_mais_energia(raio,local_formiga);
            ++it;
        }
    }
}

int Mundo::best_quadrante_to_runaway(Comunidade* comunidade, int raio_de_visao, Ponto local_formiga) {
    srand(time(NULL));
    bool quadrantes_livres[4] = {true,true,true,true};
    int aux;
    auto it= comunidades.cbegin();
    while(it != comunidades.cend()){
        if( it->getNinhoId() == comunidade->getNinhoId()){
            ++it;
        }else{
            for(int i=0;i<it->getNFormigas();i++){
                aux=it->ckif_formiga_num_raio_visao_quadrante(local_formiga,raio_de_visao,i);
                switch(aux){
                    case 0: 
                        quadrantes_livres[0]=false;
                        break;
                    case 1: 
                        quadrantes_livres[1]=false;
                        break;
                    case 2: 
                        quadrantes_livres[2]=false;
                        break;
                    case 3:
                        quadrantes_livres[3]=false;
                        break;         
                }
            }
            ++it;
        }  
    }
    if(quadrantes_livres[0])
        return 0;
    if(quadrantes_livres[1])
        return 1;
    if(quadrantes_livres[2])
        return 2;
    if(quadrantes_livres[3])
        return 3;
    return (rand() % 4);
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
    bool aux;
    while(it != comunidades.end()){
        if(it->getNinhoId() == id_n){
            aux=it->criaFormigas(quantas,tipo);
            return aux;
        }
        it++;
    }
    return false;
}

bool Mundo::cria1formiga(char tipo, int id_n, int linha, int coluna) {
    auto it = comunidades.begin();
    bool aux;
    if(mckif_noants_nonest(linha, coluna)){
        while(it != comunidades.end()){
            if(it->getNinhoId() == id_n){
                aux=it->cria1Formiga(tipo, linha, coluna);
                return aux;
            }
            it++;
        }
    }
    return false;
}

int Mundo::getLimite() const{
    return limite;
}

void Mundo::migalhas_iniciais(){
    srand (time(NULL));
    
    for(int i=0;i<limite;i++){
        for(int j=0;j<limite;j++){
            if((rand()%100) < p_init_migalhas){
                criamigalha(i, j);
            }
        }
    }
}

void Mundo::novas_migalhas_iter(){
    int num, auxx, auxy;
    srand (time(NULL));
    
    num = rand()%(migalhas_iter+1);
    
    for(int i=0;i<num;i++){
        do{
            auxx = rand()%limite;
            auxy = rand()%limite;
        }while(!mckif_space_isempty(auxx, auxy));
        criamigalha(auxx, auxy);
    }
}

void Mundo::updatemap(){
    int i, j;
    Ponto aux(0,0);
    Interface::printborders(janela, pfoca);
    for(i=0;i<comunidades.size();i++){
        for(j=0;j<comunidades[i].getNFormigas();j++){
            aux=comunidades[i].getPontoFormiga(j);
            if(aux.getX() >= pfoca.getX() && aux.getX() < (pfoca.getX()+25) && aux.getY() >= pfoca.getY() && aux.getY() < (pfoca.getY()+25)){
                aux.setX(aux.getX()-pfoca.getX());
                aux.setY(aux.getY()-pfoca.getY());
                Interface::printcaracter(aux, comunidades[i].getNinhoId(), comunidades[i].getTipoFormiga(j), janela);
            }
        }
        aux = comunidades[i].getNinhoPonto();
        if(aux.getX() >= pfoca.getX() && aux.getX() < (pfoca.getX()+25) && aux.getY() >= pfoca.getY() && aux.getY() < (pfoca.getY()+25)){
            aux.setX(aux.getX()-pfoca.getX());
            aux.setY(aux.getY()-pfoca.getY());
            Interface::printcaracter(aux, comunidades[i].getNinhoId(), 78, janela);
        }
    }
    for(i=0;i<migalhas.size();i++){
        aux = migalhas[i].getPonto();
        if(aux.getX() >= pfoca.getX() && aux.getX() < (pfoca.getX()+25) && aux.getY() >= pfoca.getY() && aux.getY() < (pfoca.getY()+25)){
            aux.setX(aux.getX()-pfoca.getX());
            aux.setY(aux.getY()-pfoca.getY());
            Interface::printcaracter(aux, 12, 254, janela);
        }
    }
}

Mundo::~Mundo() {
}

