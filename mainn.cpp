#include "ponto.h"
#include <iostream>
using namespace std;

int main(){
    Ponto point,point2;
    point.iniciar(3,4);
    //point.mover(1,2);
    //cout<< "A distancia do ponto ate a origem" << point.distOrig() << endl;
    //point.cord();
    point2.iniciar(9,12);
    cout<< point2.dist(point) << endl;
    return 0;
}