#ifndef MATRIX_H
#define MATRIX_H
// matrix.h (header file)
#include <iostream>
#include <fstream>
#include <string>

using namespace std;



template <class T> 
class Matrix;
template <class T> 
std::ostream& operator<< (std::ostream&, const Matrix<T>&);

template <class T>
class Matrix {
private:

	T** m; // m é um array 2D a ser implementado como um pointer de pointers
	int nRows;  // numero de linhas
	int nCols;  //  numero de colunas

public:

	// Construtores
	Matrix<T>(); 
	//NOVO CODIGO
	Matrix<T>(int rows, int cols, const T& value = 0.0);
	Matrix<T>(std::ifstream &myFile);
	Matrix<T>(const Matrix<T> &that);
	//
	// destrutor
	~Matrix<T>();

	// basic getters
	int rows() const;
	int cols() const;
	T& get(int ls, int cs) const;
	//

	// other methods
	void transpose();
	void print() const;
	//NOVOS METODOS
	void unit();
	void zeros();
	void ones();
    //Sobrecargas de operadores
    Matrix<T>& operator= (const Matrix<T>& );
    Matrix<T> operator+ (const Matrix<T>&);
	Matrix<T>& operator+= (const Matrix<T>&);
	Matrix<T> operator- (const Matrix<T>&);
	Matrix<T>&operator-= (const Matrix<T>&);
	T& operator() (int, int) const;
    Matrix<T> operator~ ();
	Matrix<T>& operator*= (double);
	Matrix<T> operator* (const Matrix<T>&);
	Matrix<T>& operator*= (const Matrix<T>&);
	bool operator== (const Matrix<T>&) const;
	bool operator!= (const Matrix<T>&) const;
	friend std::istream& operator>> (std::istream&, Matrix<T>&);
	friend std::ostream& operator<< <>(std::ostream&, const Matrix<T>&);

};



template <class T>
Matrix<T>::Matrix() 
{
	nRows = 0;
	nCols = 0;
	m = NULL;
}

template <class T>
Matrix<T>::Matrix(int rows, int cols, const T& value) 
{
	if ((rows> 0) && (cols > 0)){
		nRows = rows;
		nCols = cols;
		
		m = new T*[nRows];
		for (int i = 0; i < nRows; i++)
			m[i] = new T[nCols];
		for (int i = 0; i < nRows; i++) {
			for (int j = 0; j < nCols; j++)
				m[i][j] = value;
		}
	}
	else {
		throw "Parametros incorretos para criar uma matriz" ;
		
	}
}

template <class T>
Matrix<T>::Matrix(std:: ifstream &myFile)
{
	if (myFile.fail() == 1) 
	{
		cout << " Arquivo fonte de texto nao encontrado \n Favor verificar a existencia do arquivo myfile.txt no diretorio de origem\n" << endl;
	}
	else 
	{
		myFile >> nRows;
		myFile >> nCols;
		//cout << "n:" << nRows << " - " << nCols << endl;

		m = new T*[nRows];
		for (int i = 0; i < nRows; i++)
			m[i] = new T[nCols];

		for (int i = 0; i < nRows; i++)
			for (int j = 0; j < nCols; j++)
				myFile >> m[i][j];	
	}
}

template <class T>
Matrix<T>::Matrix(const Matrix<T> &that)
{
	this->nRows = that.nRows;
	this->nCols = that.nCols;
	this->m = new T*[nRows];

	for (int i = 0; i < this->nRows; i++)
		this->m[i] = new T[this->nCols];
	for (int i = 0; i < this->nRows; i++) {
		for (int j = 0; j < this->nCols; j++)
			this->m[i][j] = that.m[i][j];
	}
}

// destrutor
template <class T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < nRows; i++)
		delete[] m[i];
	delete [] m;
}
// obtem o numero de linhas
template <class T>
int Matrix<T>::rows() const 
{
	return nRows;
}
// obtem o numero de colunas
template <class T>
int Matrix<T>::cols() const 
{
	return nCols;
}

template <class T>
T& Matrix<T>::get(int ls, int cs) const
{
	if ((ls > 0) && (cs > 0))
		if ((ls <= nRows) && (cs <= nCols))
			return m[ls - 1][cs - 1];

		else
			throw "- Posicao invalida - ";
}
// torna a matriz transposta

template <class T>
void Matrix<T>::transpose() 
{
	//Cria uma nova matriz com numero de linhas e colunsa trocadas
	//copia os elementos da matriz X para a nova matriz
	//troca os ponteiros duplos para que o destruir do objeto desaloque
	//as memorias de matrizes nao utilizadas
	Matrix<T> Y(nCols, nRows);

	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++)
			Y.m[j][i] = m[i][j];
	}
	
	double **temp;
	// Reapontamento dos apontadores da matriz
	temp = m;
	m = Y.m;
	Y.m = temp;
	// Troca do numero de linhas e colunas da matriz transposta
	nCols = Y.nCols;
	nRows = Y.nRows;
}

// imprime o conteudo da matriz
template <class T>
void Matrix<T>::print() const 
{
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++)
			cout << m[i][j]<< " ";
		cout << "\n";
	}
	cout << endl;
}

//NOVOS METODOS
template <class T>
void Matrix<T>::unit()
{
	if (nRows == nCols) {
		this->zeros();
		for (int i = 0; i < nRows; i++)
			this->m[i][i] = 1.0;
	}	
}

template <class T>
void Matrix<T>::zeros() 
{
	for (int i = 0; i < nRows; i++)
		for (int j = 0; j < nCols; j++)
			m[i][j] = 0.0;
}

template <class T>
void Matrix<T>::ones()
{
	for (int i = 0; i < nRows; i++)
		for (int j = 0; j < nCols; j++)
			m[i][j] = 1.0;
}

//Métodos para a atividade 05
template <class T>
Matrix<T>& Matrix<T>::operator= (const Matrix<T>& n){
    if(this == &n){
		return *this;
	}
	this->nRows = n.nRows;
    this->nCols = n.nCols;
    if(this->m != NULL){
        for(int i = 0; i < nRows; i++){
            delete[] this->m[i];
        }
        delete[] this->m;
    }
    this->m = new T* [nRows];
    for(int i = 0; i < nRows; i++){
        this->m[i] = new T [nCols];
    }
    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < nCols; j++){
            this->m[i][j] = n.m[i][j];
        }
    }
    return *this;
}

template <class T>
Matrix<T> Matrix<T>::operator+ (const Matrix<T>& n){
        if(this->nRows == n.nRows && this->nCols == n.nCols){
            Matrix aux(this->nRows,this->nCols,0);
            for(int i = 0; i < this->nRows; i++){
                for(int j = 0; j < this->nCols; j++){
                    aux.m[i][j] = this->m[i][j] + n.m[i][j];
                }
            }
            return aux;
        }else{
			Matrix<T> aux(this->nRows,this->nCols,0);
			return aux;      
		}
}

template <class T>
Matrix<T> Matrix<T>::operator- (const Matrix<T>& n){
	if (this->nRows == n.nRows && this->nRows == n.nCols){
		Matrix aux(this->nRows,this->nCols);
            for(int i = 0; i < this->nRows; i++){
                for(int j = 0; j < this->nCols; j++){
					aux.m[i][j] = this->m[i][j] - n.m[i][j];
				}
			}
		return aux;
	}else{
		Matrix aux(this->nRows,this->nCols);
		return aux;
	}
}

template <class T>
Matrix<T>& Matrix<T>::operator+= (const Matrix<T>& n){
	if(this->nRows == n.nRows && this->nCols == n.nCols){
            for(int i = 0; i < this->nRows; i++){
                for(int j = 0; j < this->nCols; j++){
                    this->m[i][j] = this->m[i][j] + n.m[i][j];
                }
            }
            return *this;
        }else{
            throw " -Operacao impossivel para matrizes de diferentes dimensoes- ";
        }
}

template <class T>
Matrix<T>& Matrix<T>::operator-= (const Matrix<T>& n){
	if(this->nRows == n.nRows && this->nCols == n.nCols){
            for(int i = 0; i < this->nRows; i++){
                for(int j = 0; j < this->nCols; j++){
                    this->m[i][j] = this->m[i][j] - n.m[i][j];
                }
            }
            return *this;
        }else{
            throw "Operacao impossivel para matrizes de diferentes dimensoes- ";
        }
}

template <class T>
T& Matrix<T>::operator() (int ls, int cs) const{
	if ((ls > 0) && (cs > 0))
		if ((ls <= nRows) && (cs <= nCols))
			return this->m[ls - 1][cs - 1];
	else
		throw "- Posicao invalida - ";
}

template <class T>
Matrix<T> Matrix<T>::operator~ (){
	Matrix aux = *this;
	aux.transpose();
	return aux;
}

template <class T>
Matrix<T>& Matrix<T>::operator*= (double cnt){
	for(int i = 0; i < this->nRows; i++){
        for(int j = 0; j < this->nCols; j++){
            this->m[i][j] = cnt * this->m[i][j];
        }
    }
	return *this;
}

template <class T>
Matrix<T> Matrix<T>::operator* (const Matrix<T>& n){
	if (this->nCols == n.nRows){
		Matrix aux(this->nRows,n.nCols);
		for (int i = 0; i < this->nRows; i++)
		{
			for (int j = 0; j < n.nCols; j++)
			{
				for (int k = 0; k < this->nCols; k++)
				{
					aux.m[i][j]+= this->m[i][k] * n.m[k][j];
				}
			}
		}	
		return aux;
	}else{
		 throw " -operacao invalidade entre as matrizes- ";
	}
	
}

template <class T>
Matrix<T>& Matrix<T>::operator*= (const Matrix<T>& n){
	if (this->nCols == n.nRows){
		Matrix aux(this->nRows,n.nCols);
		for (int i = 0; i < this->nRows; i++)
		{
			for (int j = 0; j < n.nCols; j++)
			{
				for (int k = 0; k < this->nCols; k++)
				{
					aux.m[i][j]+= this->m[i][k] * n.m[k][j];
				}
			}
		}	
		return *this = aux;
	}else{
		throw " -Operacao impossivel para matrizes de diferentes dimensoes- ";
	}
}

template <class T>
bool Matrix<T>::operator== (const Matrix<T>& n) const{
	if(this->nRows == n.nRows && this->nCols == n.nCols){
		for(int i = 0; i < this->nCols;i++){
			for(int j = 0; j < this->nCols; j++){
				if(this->m[i][j] != n.m[i][j]){
						return false;
				}
			}
		}
		return true;
	}else{
		return false;
	}
}

template <class T>
bool Matrix<T>::operator!= (const Matrix<T>& n) const{
	if(this->nRows == n.nRows && this->nCols == n.nCols){
		for(int i = 0; i < this->nCols;i++){
			for(int j = 0; j < this->nCols; j++){
				if(this->m[i][j] != n.m[i][j]){
						return true;
				}
			}
		}
		return false;
	}else{
		return true;
	}
}

template <class T>
istream& operator>> (istream& input, Matrix<T>& n){
	for (int i = 0; i < n.nRows; i++) {
		for (int j = 0; j < n.nCols; j++)
			input >> n.m[i][j];
	}
	return input;
}

template <class T>
ostream& operator<< (ostream& output, const Matrix<T>& n){
	for (int i = 0; i < n.nRows; i++) {
		for (int j = 0; j < n.nCols; j++)
			output << n.m[i][j] << " ";
		output << "\n";
	}
	output << "\n";
	return output;
}


#endif //MATRIX_H