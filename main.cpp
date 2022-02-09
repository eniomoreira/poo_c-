#include "matriz.h"

using namespace std;

int main(){
    Matrix Y(3,2);
    Matrix X(4,1);
    
    std::cout << "Y:: " << std::endl;
    Y.print();
    std::cout << "Numero de linhas de Y:: " << Y.getRows() << endl;
    std::cout << "Numero de colunas de Y:: " << Y.getCols() << endl;
   
    std::cout << "Transposta de Y:: " << std::endl;
    Y.transpose();
    Y.print();
    std::cout << "Numero de linhas de Y:: " << Y.getRows();
    std::cout << "Numero de colunas de Y:: " << Y.getCols();
    
    std::cout << std::endl << "X:: " << std::endl;
    X.print();
    
    std::cout << "Numero de linhas de X:: " << X.getRows();
    std::cout << "Numero de colunas de X:: " << X.getCols();
   
    return 0;
}