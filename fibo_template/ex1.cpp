#include <iostream>

using namespace std;

template <class T>
T divisao ( T& a, T& b){
    return ( a / b);
}

int main(){
    int a = 1, b = 3;
    float c = 1.2, d = 2.4;
    double e = 2.7, f = 7.5;
    cout << divisao(a,b) << endl;
    cout << divisao(c,d) << endl;
    cout << divisao(e,f) << endl;

    return 0;
}