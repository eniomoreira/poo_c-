// Ponto2D.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include "ponto2D.h"
using namespace std;

int main()// Programa teste
{
	Ponto A, C, D (11.02,13.65);
	Ponto B(3.65, 5.33);

	cout << "Total de pontos criados:: " << A.getNextId()<<endl;

	cout << "imprime ponto A:" << endl;
	A.print();

	cout << "imprime ponto B:" << endl;
	B.print();

	A.sumOf(B);
	cout << "imprime soma de A= A+B:" << endl;
	A.print();

	C = A.sumOf_(B); // ERRO FUNÇÃO ESTA ALTERANDO O NUMERO DE PONTOS CRIADO INICIALMENTE
	cout << "imprime soma C= A+B:" << endl;
	C.print();

	double x = B.distToOrig();
	cout << "Distancia do ponto B a origem 0,0: " << x << endl;

	x = B.distTo(D);
	cout << "Distancia do ponto B ao ponto D: " << x << endl;

	cout << "Total de pontos criados:: " << D.getNextId() << endl;

    return 0;

}
