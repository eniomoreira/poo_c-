#ifndef PONTO_H
#define PONTO_H

class Ponto{
    private:
        double _x;
        double _y;
    public:
      void iniciar(double x, double y);
      void mover(double x1, double y1);
      double distOrig();
      double dist(Ponto &ponto);
      void cord();
};
#endif