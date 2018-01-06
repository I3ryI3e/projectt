#include "Interface.h"
#include <iostream>
#include <sstream>

Interface::Interface(): file(nullptr), estado(0){
    mundos.push_back(Mundo("default"));
    iterador=mundos.begin();
}

void Interface::inicia() {
    string linha, aux;
    initial_screen();
    do{
        if(estado == 1 || estado == 3){
            iterador->updatemap(*this);
        }else{
            screen_config_stage();        //AS MENSAGENS DE ERRO TAO MAL AGORA
        }
        if(estado == 0 || estado == 1){
            linha = getlinha();
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
                    mostrainfo("\n\t\t    Erro a abrir o ficheiro.");  //MUDAR
                    estado -= 2;
                    continue;
                }
                getline(file,linha);
            }
        istringstream iss(linha);
        iss >> aux;
        if(linha.compare("sair") != 0 || aux.compare("guarda") !=0 || aux.compare("apaga") !=0 || aux.compare("muda") !=0)
            estado=iterador->tratacmd(linha,estado,*this);
        else if(aux.compare("sair") !=0 )
            if(aux.compare("guarda") == 0)
                guardaMundos(linha);
            else if(aux.compare("apaga") == 0)
                apagaMundos(linha);
            else
                mudaMundo(linha);
        
    }while(linha.compare("sair") != 0);
}

void Interface::apagaMundos(string linha) {
    istringstream iss(linha);
    string aux,nome_Mundo_Atual;
    iss >> aux >> aux;
    auto it = mundos.begin();
    nome_Mundo_Atual=iterador->getNome();
    while(it != mundos.end()){
        if(it->getNome() == aux){
            if(it == iterador)
                iterador=it= mundos.erase(it);
            else
                it=mundos.erase(it);
        }else
            ++it;  
    }
}

void Interface::guardaMundos(string linha) {

}

void Interface::mudaMundo(string linha) {
    istringstream iss(linha);
    string aux;
    iss >> aux >> aux;
    auto it=mundos.cbegin();
    while(it != mundos.cend()){
        if(it->getNome() == aux){
            iterador=it;
            return;
        }
        ++it;
    }
    return;
}

void Interface::initial_screen(){
    Consola::setScreenSize(30, 120);
    Consola::setTextColor(Consola::VERDE_CLARO);
}

void Interface::screen_config_stage(){
    Consola::gotoxy(20, 14);
    cout << "Bem vindo ao programa de simulacao de populacoes de formigas" << endl;
    Consola::gotoxy(20, 15);
    cout << "Trabalho pratico de POO 2017/2018" << endl;
    Consola::gotoxy(20, 16);
    cout << "Comando: ";
}

void Interface::printborders(int lim, Ponto foca){
    int i, j, l=foca.getX(), c=foca.getY(), k=-3;
    while(l>10){
        l -= 10;
    }
    while(c>10){
        c -= 10;
    }
    for(i=-2;i<=lim;i++){
        for(j=119;j>=(117-lim);j--, k+=2){
            Consola::setTextColor(Consola::BRANCO_CLARO);
            Consola::gotoxy(j, i+2);
            if(i==-2 && j<=117 && j>(117-lim)){
                Consola::gotoxy(j-lim+k, 0);
                cout << c++;
                if(c==10)
                    c=0;
                continue;
            }
            if(j==119 && i>=0 && i<lim){
                cout << l++;
                if(l==10)
                    l=0;
                continue;
            }
            if(i==-1 && j==118){
                cout << (char)187;
                continue;
            }
            if(i==lim && j==118){
                cout << (char)188;
                continue;
            }
            if(i==-1 && j==(117-lim)){
                cout << (char)201;
                continue;
            }
            if(i==lim && j==(117-lim)){
                cout << (char)200;
                continue;
            }
            if(i==-1 && j!=119){
                cout << (char)205;
                continue;
            }
            if(j==118 && i!=-2){
                cout << (char)186;
                continue;
            }
            if(i==lim && j!=119){
                cout << (char)205;
                continue;
            }
            if(j==(117-lim) && i!=-2){
                cout << (char)186;
                continue;
            }
            cout << (char)255;
        }
        cout << endl;
    }
    Consola::gotoxy(79, 28);
    cout << "Canto superior esquerdo -> " << foca.obtemXY() << endl;
}

void Interface::printcaracter(Ponto aux, int i, int car, int lim){
    Consola::setTextColor(Consola::AZUL+i);
    Consola::gotoxy(aux.getX()+(118-lim), aux.getY()+2);
    cout << (char)car;
}

string Interface::getlinha(){
    string lin;
    Consola::setTextColor(Consola::VERDE_CLARO);
    getline(cin, lin);
    Consola::clrscr();
    Consola::gotoxy(0,1);
    return lin;
}

void Interface::mostrainfo(string aux){cout << aux;}

void Interface::clrscreen(){Consola::clrscr();}

void Interface::gotox0y0(){Consola::gotoxy(0,0);}