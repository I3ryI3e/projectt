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
    do{
        if(estado == 1 || estado == 3){
            updatemap();
            Consola::gotoxy(0,0);
        }else{
            ecran.setconfig_screen();
            //setconfig_screen();             //AS MENSAGENS DE ERRO TAO MAL AGORA
        }
        if(estado == 0 || estado == 1){
            getline(cin, linha);            
            Consola::clrscr();              //REVER ESTA LINHA
            Consola::gotoxy(0, 1);          //REVER ESTA LINHA
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
    string aux;
    if(linha.compare("inicio") == 0 && (estado == 0 || estado == 2)){
        if(ckif_notconfig() == false){
            estado += 1;
            Consola::clrscr();
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
    if(aux.compare("listamundo") == 0 && (estado == 1 || estado == 3)){
        auto it = comunidades.cbegin();
        while(it != comunidades.cend()){
            cout << it->getInfoGeral() << endl;
            ++it;
        }
        auto iter = migalhas.cbegin();
        cout << "Migalhas:" << endl;
        while(iter != migalhas.cend()){
            cout << iter->getInfo() << endl;
            ++iter;
        }
        return estado;
    }
    if(aux.compare("listaninho") == 0 && (estado == 1 || estado == 3)){
        int nninho;
        iss >> nninho;
        auto it = comunidades.cbegin();
        while(it != comunidades.cend()){
            if(nninho == it->getNinhoId()){
                cout << it->getInfoNinho() << endl;
                return estado;
            }
            ++it;
        }
        return estado;
    }
    if(aux.compare("listaposicao") == 0 && (estado == 1 || estado == 3)){
        int lin, col;
        iss >> lin >> col;
        Ponto auxP(lin,col);
        auto it = comunidades.cbegin();
        while(it != comunidades.cend()){
            cout << it->ckwhoisthere(auxP);
            ++it;
        }
        auto iter = migalhas.cbegin();
        while(iter != migalhas.cend()){
            if(iter->getPonto() == auxP)
                cout << iter->getInfo();
            ++iter;
        }
        
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
        cout << oss.str() << endl;
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
    for(i=-1;i<=getLimite();i++){
        for(j=118;j>=(117-getLimite());j--){
            Consola::setTextColor(Consola::BRANCO_CLARO);
            Consola::gotoxy(j, 0+i+1);
            if(i==-1 && j==118){
                cout << (char)187;
                continue;
            }
            if(i==getLimite() && j==118){
                cout << (char)188;
                continue;
            }
            if(i==-1 && j==(117-getLimite())){
                cout << (char)201;
                continue;
            }
            if(i==getLimite() && j==(117-getLimite())){
                cout << (char)200;
                continue;
            }
            if(i==-1){
                cout << (char)205;
                continue;
            }
            if(j==118){
                cout << (char)186;
                continue;
            }
            if(i==getLimite()){
                cout << (char)205;
                continue;
            }
            if(j==(117-getLimite())){
                cout << (char)186;
                continue;
            }
            cout << (char)255;
        }
        cout << endl;
    }
    for(i=0;i<comunidades.size();i++){
        Consola::setTextColor(Consola::VERDE+i);
        Consola::gotoxy(comunidades[i].getNinhoPonto().getX()+(118-getLimite()), comunidades[i].getNinhoPonto().getY()+1);
        cout << (char)78;
        for(j=0;j<comunidades[i].getNFormigas();j++){
            aux=comunidades[i].getPontoFormiga(j);
            Consola::gotoxy(aux.getX()+(118-getLimite()),aux.getY()+1);
            cout << (char)190;
        }
    }
    Consola::setTextColor(Consola::COR_DE_ROSA);
    for(i=0;i<migalhas.size();i++){
        Consola::gotoxy(migalhas[i].getPonto().getX()+(118-getLimite()), migalhas[i].getPonto().getY()+1);
        cout << (char)254;
    }
}

//void Mundo::setconfig_screen(){
//    Consola::setTextColor(Consola::VERDE_CLARO);
//    Consola::clrscr();
//    Consola::setScreenSize(30, 120);
//    Consola::gotoxy(20, 14);
//    cout << "Bem vindo ao programa de simulacao de populacoes de formigas" << endl;
//    Consola::gotoxy(20, 15);
//    cout << "Trabalho pratico de POO 2017/2018" << endl;
//    Consola::gotoxy(20, 16);
//    cout << "Comando: ";
//}

Mundo::Mundo(const Mundo& orig) {
}

Mundo::~Mundo() {
}

