#include "Extrato.h"
#include <string>
#include <iostream>
using namespace std;


Extrato::Extrato(double valorNaConta, double &Movimentacao, string TypeMove)
{
	_valorNaConta=valorNaConta;
	_Movimentacao=Movimentacao;
	_TipoMovimentacao=TypeMove;
}


Extrato::~Extrato()
{
}

double Extrato::get_ValorNaConta()
{
	return _valorNaConta;
}
double Extrato::get_Movimentacao()
{
	return _Movimentacao;
}
string Extrato::get_TipoMovimentacao()
{
	return _TipoMovimentacao;
}

void Extrato::printDados()
{
	cout << this->get_TipoMovimentacao() << "::" << this->get_Movimentacao() << "::" << this->get_ValorNaConta()<<"::"<<endl;

}
