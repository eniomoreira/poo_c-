//AP 1.2: comprime.cpp
//Comprime um vetor suprimindo repetições dos números vizinhos

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector <int> vin, vout, vout2;
    int aux;
    //bool a = true;
    cin >> aux;
    while(aux >= 0){
        vin.push_back(aux);
        cin >> aux;
    }
    for (int i = 0; i < vin.size(); ){
        int iterator = 1;
        int aux1 = i;
        while(vin[aux1] == vin[aux1+1]){
            iterator ++;
            aux1++;
        }
        vout.push_back(iterator);
        vout.push_back(vin[i]);
        i += iterator;
        iterator = 1;
    
    }
    cout << "vetor comprimido: ";
    for (int i = 0; i < vout.size(); i++){
        cout << vout[i] << " ";
    }
    cout<<endl;

    for(int i = 0; i < vout.size(); i+= 2){
        int aux = vout[i];
        while(aux > 0){
            vout2.push_back(vout[i+1]);
            aux--;
        }
    }   
     cout << "vetor descomprimido: ";
    for (int i = 0; i < vout2.size(); i++){
        cout << vout2[i] << " ";
    }
    cout<<endl;
    return 0;
}