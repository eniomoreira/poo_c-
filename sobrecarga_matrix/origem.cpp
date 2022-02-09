// main.cpp
#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
    ifstream in("myMatrix.txt");
    Matrix Y;
    Matrix J;
    Matrix X(3,2,1.0), A(3,3), C(3,3),D(2,3,1.0);
    Matrix Z(3,2,7.0);
    Matrix W(in);
    X.print();
    D.print();
    Y = D*X;
    Y.print();
    // operadores a serem implementados em sua classe:
    //Y = W;
    //Y.print();
    //Y+= W;
    //Y.print();
    //Y+= W;
    //Y.print();
    //A.print();
    //A(2,1) = 10;
    //A.print();
    //C = A + A;
    //C.print();                                  // Soma
    //C -= A;
    //C.print();                                    // Subtração       
    //A = C - A;
    //A.print();                                  // Subtração
    //A += A;                                   // Soma
    //A = ~C;
    //A.print();
    //X.print();                                  // A é igual a transposta de C
    //X *= 2;
    //X.print();
   // A.print();
    //C.print();                                   // multiplicação por uma constante
    //C = C*X;
    //C.print(); 
    //C *= X;
    //C.print();                                        // multiplicação de matrizes                                            // multiplicação de matrizes
    //bool t = (X == D);
    //cout << t << endl;                                 // verifica a igualdade entre A e C
    //if(X != Y)                                  // verifica a desigualdade entre A e C
    //cout << Z << endl;                        // impressão de matrizes
    //cin >> W                                        // leitura de dados para dentro da matriz Y 
    in.close();
    return 0;
}