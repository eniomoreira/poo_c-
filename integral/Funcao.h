#ifndef FUNCAO_H
#define FUNCAO_H
class Funcao
{
public:
	Funcao();
	//funcao que obtem a integral da funcao pela regra do trapezio
	double getIntegral(double limiteInferior, double limiteSuperior, double intervalos);
	
	// funcao virtual representando a funcao cuja integral deve ser calculada
	virtual double func(double input) = 0;
	// destrutor
	~Funcao();
};

class Quadratica : public Funcao
{
public:
	Quadratica(double a, double b, double c);
	double func(double input);
	~Quadratica();
private:
	double _a, _b, _c;

};

class Senoide: public Funcao
{
public:
	Senoide();
	double func(double input);
	~Senoide();
private:
	
};

class Linear : public Funcao
{
public:
	Linear(double a, double b);
	double func(double input);
	~Linear();
private:
	double _a, _b;

};
#endif