#include <iostream>
#include <math.h>
#include "metodotrapecio.h"

using namespace std;

double f(double x) {
    return log(pow(x, 4));
}

int main()
{
    MetodoTrapecio metodo_trapecio(1, 50, 100000);
    cout<<metodo_trapecio.calcular_integral(f)<<endl;

    return 0;
}
