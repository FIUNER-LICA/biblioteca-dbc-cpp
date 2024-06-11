#ifndef METODOTRAPECIO_H
#define METODOTRAPECIO_H
#include "contract.h"

class MetodoTrapecio : protected contract::Invariant<MetodoTrapecio>
{
public:
    MetodoTrapecio(double _a, double _b, int _n);

    double calcular_integral(double (*func)(double));
private:
    double a;
    double b;
    double n;

    double step(double (*func)(double), double x, double h);
};

#endif // METODOTRAPECIO_H
