#include <iostream>
#include <cstdlib> // system()
using namespace std;
#include "list.h"

void clearscreen() {
if (system( "clear" )) system( "cls" );
}

int main(int argc, char *argv[])
{
    // Cria Lista
    List<int> A;
    cout << "Criacao da Lista A:" << endl;
    cout << "-> Lista A: " << A << endl;
    
    try 
	{
		A.erase(800);// antes era 6
		cout << "A.erase(12)" << endl;
		cout << "-> Lista A " << A << endl;
	}
	catch (Erro &e) 
	{
		e.out();
			//Uma possibilidade correção seria inserir um elemento a lista
			// para continuar a execução do programa
			
			//caso nao, o programa sai do catch e retorna as execuções sequenciais apos o throw, se possivel
	}
    
    //Insere elementos no Final da lista
    A.push_back(3);
    A.push_back(4);
    A.push_back(5);
    A.push_back(6);
    A.push_back(6);
    A.push_back(1);
    A.push_back(2);
    cout << "A.push_back(3), A.push_back(4), A.push_back(5), A.push_back(6), A.push_back(6), A.push_back(1), A.push_back(2)" << endl;
    cout << "-> Lista A " << A << endl;
    
    //Insere elementos no Inicio da lista
    A.push_front(8);
    A.push_front(9);
    A.push_front(4);
    A.push_front(9);
    cout << "A.push_front(8), A.push_front(9), A.push_front(4), A.push_front(9)" << endl;
    cout << "-> Lista A " << A << endl;

    // Teste

    
    // remove os elementos de valor igual a 6 existentes na lista 
    /*A.erase(6);
    cout << "A.erase(6)" << endl;
    cout << "-> Lista A " << A << endl;
    
    // retorna o tamanho da lista
    int tam;
    tam = A.size();
    cout << "tam = A.size" << endl;
    cout << "-> tamanho da Lista A = " << tam << endl << endl;*/
     
    cout << "\nPressione qualquer tecla para continuar...";
    getchar();
    clearscreen();
    
}