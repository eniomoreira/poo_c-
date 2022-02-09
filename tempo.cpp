#include "tempo.h"
#include <iostream>

using namespace std;

void Tempo::verificaTempo(){
    while(_seg >= 60){
        _min ++;
        _seg -= 60;
    }
    if(_seg == -60){
        _seg = 0;
        _min --;
    }
    while (_min >= 60){
        _hora ++;
        _min -= 60;
    }
    if(_min == -60){
        _min = 0;
        _hora --;
    }
    while (_hora > 23)
    {
        _dia ++;
        _hora -= 23;
    }
    if(_hora == -23){
        _hora = 0;
        _dia--;
    }
    if(_dia < 0){
        cout << "------ESSA MEDIDA PARA O TEMPO E INVALIDA------"<< endl;
    }
     
}
Tempo::Tempo(int dia, int hora,int min, int seg){
    _dia = dia;
    _hora = hora;
    _min = min;
    _seg = seg;
    this->verificaTempo();
}
Tempo Tempo::somaTempo(const Tempo x){
    this->_dia += x._dia;
    this->_hora += x._hora;
    this->_min += x._min;
    this->_seg += x._seg;
}
void Tempo::imprimeTempo(){
    cout << "Dia: " << this->_dia << endl;
    cout << "Hora: " << this->_hora << endl;
    cout << "Minutos: " << this->_min << endl;
    cout << "Segundos: " << this->_seg << endl;
    cout << endl;
}
void Tempo::incrementaTempo(){
    this->_seg ++;
    this->verificaTempo();
}
void Tempo::decrementaTempo(){
    this->_seg--;
    this->verificaTempo();

}