#include "Funcao.h"
#include <cmath>
//METODOS DA CLASSE FUNCAO

Funcao::Funcao()
{
}

Funcao::~Funcao()
{
}

double Funcao::getIntegral(double limiteInferior, double limiteSuperior, double intervalos)
{
	double Soma = 0;
	double h = (limiteSuperior - limiteInferior) / intervalos;

	for (double i = limiteInferior+h; i < limiteSuperior; i += h)
	{
		Soma +=2*func(i);
	}
	return (h/2)*(Soma+((func(limiteInferior)+func(limiteSuperior))));
}


//METODOS DA CLASSE QUADRATICA
Quadratica::Quadratica(double a, double b, double c)
{
	_a = a;
	_b = b;
	_c = c;
}

Quadratica::~Quadratica()
{
}

double Quadratica::func(double input)
{
	return _a * pow(input, 2) + _b * input + _c;
}

//METODOS DA CLASSE SENOIDE
Senoide::Senoide()
{
}

double Senoide::func(double input)
{
	if (input == 0)
		return 1;

	return sin(input)/input;
}
Senoide::~Senoide()
{
}

//METODOS DA CLASSE LINEAR
Linear::Linear(double a, double b)
{
	_a = a;
	_b = b;
}


double Linear::func(double input)
{
	return _a * input + _b;
}
Linear::~Linear()
{
}
