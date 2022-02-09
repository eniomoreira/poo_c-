#ifndef MATRIX_H
#define MATRIX_H
// matrix.h (header file)
#include <iostream>
#include <fstream>
#include <string>


class Matrix {
private:

	double** m; // m é um array 2D a ser implementado como um pointer de pointers
	int nRows;  // numero de linhas
	int nCols;  //  numero de colunas

public:

	// Construtores
	Matrix(); 
	//NOVO CODIGO
	Matrix(int rows, int cols, const double &value = 0.0);
	Matrix(std::ifstream &myFile);
	Matrix(const Matrix &that);
	//
	// destrutor
	~Matrix();

	// basic getters
	int getRows() const;
	int getCols() const;
	//Nova função
	double get(int ls, int cs) const;
	//

	// other methods
	void transpose();
	void print() const;
	//NOVOS METODOS
	void unit();
	void zeros();
	void ones();
    //METODOS DA ATIVIDADE 05
    Matrix& operator= (const Matrix& );
    Matrix operator+ (const Matrix&);
	Matrix& operator+= (const Matrix&);
	Matrix operator- (const Matrix&);
	Matrix&operator-= (const Matrix&);
	double& operator() (int, int) const;
    Matrix operator~ ();
	Matrix& operator*= (double);
	Matrix operator* (const Matrix&);
	Matrix& operator*= (const Matrix&);
	bool operator== (const Matrix&) const;
	bool operator!= (const Matrix&) const;
	friend std::istream& operator>> (std::istream&, Matrix&);
	friend std::ostream& operator<< (std::ostream&, const Matrix&);

};
#endif //MATRIX_H