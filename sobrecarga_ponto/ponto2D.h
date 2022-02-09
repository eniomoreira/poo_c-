#ifndef PONTO2D_H
#define PONTO2D_H
#include <iostream>

class Ponto
{
private:
	double _x;
	double _y;
	static int _id;

public:
	//Constructor default
	Ponto(double x=0, double y=0);
	Ponto(const Ponto &Point);
	//Destructor
	~Ponto();
    // Métodos da atividade 05
    Ponto& operator-- ();
    Ponto operator+ (const Ponto& ) const;
	//Basic setters
	inline void setX(double);
	inline void setY(double);
	inline void setId(int);

	//Basic getters
	int getNextId() const ;
	inline double getX() const;
	inline double getY() const;

	//Other methods
	void print() const; // Imprimir coordenadas X e Y
	double distToOrig(); // Distancia do ponto chamada a origem  x=0 y=0 
	double distTo(const Ponto &p2); //Distancia do ponto chamado ao ponto de referencia p2
	void sumOf(const Ponto &p2); // soma o ponto p2 ao ponto chamado
	Ponto sumOf_(const Ponto &p2); // retorna um objeto ponto com a soma do ponto chamado + p2

};
#endif // PONTO2D_H

/*// formas usuais (j� implementadas)
Ponto2D p1;
Ponto2D p2(3.0, 4.0);
// inicializa��es usando o construtor de c�pia
Ponto2D p3(p1); // Ponto2D p3 � inicializado com as coordenadas do ponto p1
Ponto2D p4 = p2; // Ponto2D p4 � inicializado com as coordenadas do ponto p2
*/