//AP 1.2: comprime.cpp
//Comprime um vetor suprimindo repetições dos números vizinhos

#include <iostream>
#include <vector>

using namespace std;
void imprimeVector( const vector<int> &a,int size){
    cout << '[';
    for ( int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
    cout << ']'<< endl;

}
int main(){
    vector<int> vin,vout;
    int aux;
    cout << "---Digite numeros inteiros para o vetor----"<<endl;
    cin >> aux;
    while(aux >= 0){
        vin.push_back(aux);
        cin >> aux;
    }
    for (int i = 0; i < vin.size(); ){
        int numDeElem = 1;
        int posicao = i;
        while(vin[posicao] == vin[posicao+1]){
            numDeElem ++;
            posicao++;
        }
        vout.push_back(numDeElem);
        vout.push_back(vin[i]);
        i += numDeElem;
        numDeElem = 1;
    
    }
    imprimeVector(vin,vin.size());
    imprimeVector(vout,vout.size());
    return 0;
}