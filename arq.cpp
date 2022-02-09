//AP 1.1: arq.cpp
//Lê espaços em branco em um arquivo.
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream streamDeEntrada;
    streamDeEntrada.open("Alice.txt"); 
    char proximo;
    int espacosEmBranco = 0;
    streamDeEntrada.get(proximo);
    while(!streamDeEntrada.eof()){
        if(proximo == ' '){
            espacosEmBranco++;
        }
        streamDeEntrada.get(proximo);

    }
    cout <<"-----O numero de espacos em branco e: " << espacosEmBranco << endl;
    streamDeEntrada.close();
    return 0;
}