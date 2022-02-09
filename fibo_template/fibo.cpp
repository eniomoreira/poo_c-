#include <iostream>
using namespace std;
#include "fibo.h"

//1.1. Escreva uma função template que retorna o n - ésimo termo da série de Fibonacci 
//podendo o valor de retorno ser int , long , float , etc.

int main()
{   
	int posicao;
	//Tratamento de exceção : valor da posição menor ou igual a 0 (zero);
    int a = fibonacci(36);
    cout<< a << endl;
	cin >> posicao;
    
	try 
	{
		int n = fibonacci(posicao);
		cout << n << endl;

		long p = fibonacci(posicao);
		cout << p << endl;

		float k = fibonacci(posicao);
		cout << k << endl;

		char e = fibonacci(posicao);
		cout << e << endl;
	}

	catch (error& ex) {
		cout << " :Excecao capturada: " << ex.what() << '\n';
	}
	
	return 0;
}