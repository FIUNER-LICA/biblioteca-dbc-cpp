#include <iostream>
#include <math.h>
#include "metodotrapecio.h"
#include "../rdtsc.h"

using namespace std;

// double f(double x) {
//     return log(pow(x, 4));
// }

double f(double x) {
    double gamma = 0.9777;
    double mu = 0;
    double pi = 3.14159265359;
    return (1 / (gamma * sqrt(2 * pi))) * exp(-pow(x-mu, 2.0) / (2 * pow(gamma, 2)));
}

int main()
{
    MetodoTrapecio metodo_trapecio(-5, 5, 1000000);
    // cout<<metodo_trapecio.calcular_integral(f)<<endl;

    unsigned long long inicio, fin, ciclos_transcurridos;

    inicio=rdtsc();
    metodo_trapecio.calcular_integral(f);
    fin=rdtsc();
    ciclos_transcurridos=fin-inicio;
    cout<<ciclos_transcurridos<<endl;
    return 0;
}
