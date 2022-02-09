#include <iostream>
#include "matrix.h"
#include <fstream>

using namespace std;

//contrutor default - cria uma matriz vazia com nRows = nCols = 0  
Matrix::Matrix() 
{
	nRows = 0;
	nCols = 0;
	m = NULL;
}
Matrix::Matrix(int rows, int cols, const double &value) 
{
	if ((rows> 0) && (cols > 0)){
		nRows = rows;
		nCols = cols;
		
		m = new double*[nRows];
		for (int i = 0; i < nRows; i++)
			m[i] = new double[nCols];
		for (int i = 0; i < nRows; i++) {
			for (int j = 0; j < nCols; j++)
				m[i][j] = value;
		}
	}
	else {
		if((rows==0)&&(cols==0))
		{
			nRows = 0;
			nCols = 0;
			m = NULL;
		}
		else
		{	
		cout<<"Parametros incorretos , retornando matriz 0x0"<<endl;
		nRows = 0;
		nCols = 0;
		m = NULL;

		}
		
	}
}
Matrix::Matrix(std:: ifstream &myFile)
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

		m = new double*[nRows];
		for (int i = 0; i < nRows; i++)
			m[i] = new double[nCols];

		for (int i = 0; i < nRows; i++)
			for (int j = 0; j < nCols; j++)
				myFile >> m[i][j];	
	}
}
Matrix::Matrix(const Matrix &that)
{
	this->nRows = that.nRows;
	this->nCols = that.nCols;
	this->m = new double*[nRows];

	for (int i = 0; i < this->nRows; i++)
		this->m[i] = new double[this->nCols];
	for (int i = 0; i < this->nRows; i++) {
		for (int j = 0; j < this->nCols; j++)
			this->m[i][j] = that.m[i][j];
	}
}

// destrutor
Matrix::~Matrix()
{
	for (int i = 0; i < nRows; i++)
		delete[] m[i];
	delete [] m;
}
// obtem o numero de linhas
int Matrix::getRows() const 
{
	return nRows;
}
// obtem o numero de colunas
int Matrix::getCols() const 
{
	return nCols;
}

double Matrix::get(int ls, int cs) const
{
	if ((ls > 0) && (cs > 0)) {
		if (ls <= nRows) {
			if (cs <= nCols ) {
				return m[ls - 1][cs - 1];
			} else {
				cout << "posicao invalida - terceiro if, return -1" << endl;
				return -1;
			} 
		}
		else {
			cout << "posicao invalida - segundo if, return -1" << endl;
			return -1;
		}
	}
	else {
		cout << "posicao invalida, return -1" << endl;
		return -1;
	}
}
// torna a matriz transposta
void Matrix::transpose() 
{
	//Cria uma nova matriz com numero de linhas e colunsa trocadas
	//copia os elementos da matriz X para a nova matriz
	//troca os ponteiros duplos para que o destruir do objeto desaloque
	//as memorias de matrizes nao utilizadas
	Matrix Y(nCols, nRows);

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
void Matrix::print() const 
{
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++)
			cout << m[i][j]<< " ";
		cout << "\n";
	}
	cout << endl;
}

//NOVOS METODOS

void Matrix::unit()
{
	if (nRows == nCols) {
		this->zeros();
		for (int i = 0; i < nRows; i++)
			this->m[i][i] = 1.0;
	}	
}

void Matrix::zeros() 
{
	for (int i = 0; i < nRows; i++)
		for (int j = 0; j < nCols; j++)
			m[i][j] = 0.0;
}

void Matrix::ones()
{
	for (int i = 0; i < nRows; i++)
		for (int j = 0; j < nCols; j++)
			m[i][j] = 1.0;
}

//Métodos para a atividade 05
Matrix& Matrix::operator= (const Matrix& n){
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
    this->m = new double* [nRows];
    for(int i = 0; i < nRows; i++){
        this->m[i] = new double[nCols];
    }
    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < nCols; j++){
            this->m[i][j] = n.m[i][j];
        }
    }
    return *this;
}
Matrix Matrix::operator+ (const Matrix& n){
        if(this->nRows == n.nRows && this->nCols == n.nCols){
            Matrix aux(this->nRows,this->nCols,0);
            for(int i = 0; i < this->nRows; i++){
                for(int j = 0; j < this->nCols; j++){
                    aux.m[i][j] = this->m[i][j] + n.m[i][j];
                }
            }
            return aux;
        }else{
			Matrix aux(this->nRows,this->nCols,0);
			return aux;      
		}
}
Matrix Matrix::operator- (const Matrix& n){
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
Matrix& Matrix::operator+= (const Matrix& n){
	if(this->nRows == n.nRows && this->nCols == n.nCols){
            for(int i = 0; i < this->nRows; i++){
                for(int j = 0; j < this->nCols; j++){
                    this->m[i][j] = this->m[i][j] + n.m[i][j];
                }
            }
            return *this;
        }else{
            return *this;
        }
}
Matrix& Matrix::operator-= (const Matrix& n){
	if(this->nRows == n.nRows && this->nCols == n.nCols){
            for(int i = 0; i < this->nRows; i++){
                for(int j = 0; j < this->nCols; j++){
                    this->m[i][j] = this->m[i][j] - n.m[i][j];
                }
            }
            return *this;
        }else{
            return *this;
        }
}
double& Matrix::operator() (int ls, int cs) const{
	return this->m[ls][cs];
}
Matrix Matrix::operator~ (){
	Matrix aux = *this;
	aux.transpose();
	return aux;
}
Matrix& Matrix::operator*= (double cnt){
	for(int i = 0; i < this->nRows; i++){
        for(int j = 0; j < this->nCols; j++){
            this->m[i][j] = cnt * this->m[i][j];
        }
    }
	return *this;
}
Matrix Matrix::operator* (const Matrix& n){
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
	}
	Matrix aux;
	return aux;
}
Matrix& Matrix::operator*= (const Matrix& n){
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
	}
}
bool Matrix::operator== (const Matrix& n) const{
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
bool Matrix::operator!= (const Matrix& n) const{
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
istream& operator>> (istream& input, Matrix& n){
	for (int i = 0; i < n.nRows; i++) {
		for (int j = 0; j < n.nCols; j++)
			input >> n.m[i][j];
	}
	return input;
}
ostream& operator<< (ostream& output, const Matrix& n){
	for (int i = 0; i < n.nRows; i++) {
		for (int j = 0; j < n.nCols; j++)
			output << n.m[i][j] << " ";
		output << "\n";
	}
	output << "\n";
	return output;
}