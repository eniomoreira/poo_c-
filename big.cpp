#include <iostream>

using namespace std;

class Big{
    public:
        Big (const Big &X){
            cout << "Construtor de copia..."<< endl;
        }
        Big(){
            cout << "Contrutor default..."<<endl;
        }
        ~Big(){
            cout << "Destrutor..." << endl;
        }
};

Big bigfun(Big b){
    cout << "funcao bigfun..."<<endl;
    return b;
}

int main(){
    Big B;
    Big B3(B);
    Big B4 = B3;
    B = B3;
    cout << "1" << endl;
    B3 = bigfun(B);
    cout << "2" << endl;
    Big B5 = bigfun(B);
    cout << "3" << endl;
    return 0;
}