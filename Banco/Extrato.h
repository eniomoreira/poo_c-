#ifndef EXTRATO_H
#define EXTRATO_H

#include<ctime>
#include <string>
using namespace std;


class Extrato
{
public:
	Extrato(double valorNaConta, double &Movimentacao, string  TypeMove);
	~Extrato();
	double get_ValorNaConta();
	double get_Movimentacao();
	string get_TipoMovimentacao();
	void printDados();

private:
	double _valorNaConta;
	double _Movimentacao;
	string _TipoMovimentacao;
};

#endif