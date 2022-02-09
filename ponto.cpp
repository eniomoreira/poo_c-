#include "ponto.h"
#include <cmath>
#include <iostream>
using namespace std;
void Ponto::iniciar(double x, double y){
    _x = x;
    _y = y;
}
void Ponto::mover(double x1, double y1){
    _x += x1;
    _y += y1;
}
double Ponto::distOrig(){
    return(sqrt((this->_x * this->_x)+(this->_y * this->_y)));
}
double Ponto::dist(Ponto &ponto){
    int aux1 = this->_x - ponto._x;
    int aux2 = this->_y - ponto._y;
    return(sqrt(aux1*aux1 + aux2*aux2));
}
void Ponto::cord(){
    cout << "cordenada x: " << this->_x << endl;
    cout << "cordenada y: " << this->_y << endl;
}