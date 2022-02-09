#ifndef TEMPO_H
#define TEMPO_H

class Tempo{
    private:
        int _dia; // 0 a imlimtado;
        int _hora; // 0 a 23;
        int _min; // 0 a 59;
        int _seg; // 0 a 59;
        void verificaTempo(); // os dias não podem ser negativos!!
    public:
        Tempo(int dia = 0, int hora = 0 , int min = 0, int seg = 0);
        Tempo somaTempo(const Tempo x);
        void imprimeTempo();
        void incrementaTempo();
        void decrementaTempo();
};

#endif