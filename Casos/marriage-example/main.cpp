#include "person.h"
// #include "globals.h"
/*
 Se implementa una versión del problema del delegado dependiente en la forma
que aparece en el artículo The dependent delegate dilemma de Bertrand Meyer.
La presente es una forma de implementar en C++ los casos analizados en el
ejemplo, con el objetivo de probar una forma propia de implementar contratos que
incorporan el chequeo de invariantes.

*/

int main(int argc, char *argv[])
{
    try {
        std::printf("-----------------\n");
        std::printf("Se intenta marry_1\n");fflush(stdout);
        Person romeo;
        Person julieta;
        romeo.marry_1(julieta);
        std::printf("Ejecución exitosa de marry_1\n");fflush(stdout);
    } catch (contract::violation_error &v  ) {
        std::printf(v.what());
    } catch (std::exception &error){
        std::printf("otro tipo de error");fflush(stdout);
    }
    std::printf("Fin del intento marry_1\n\n");fflush(stdout);




    // try {
    //     std::printf("Se intenta marry_2\n");fflush(stdout);
    //     Person romeo;
    //     Person julieta;
    //     romeo.marry_2(julieta);
    //     std::printf("Ejecución exitosa de marry_2\n");fflush(stdout);
    // } catch (contract::violation_error &v  ) {
    //     std::printf(v.what());
    // } catch (std::exception &error){
    //     std::printf("otro tipo de error");fflush(stdout);
    // }
    // std::printf("Fin del intento marry2\n");fflush(stdout);

    try {
        std::printf("-----------------\n");
        std::printf("Se intenta marry_3\n");fflush(stdout);
        Person romeo;
        Person julieta;
        romeo.marry_3(julieta);
        std::printf("Ejecución exitosa de marry_3\n");
    } catch (contract::violation_error &v  ) {
        std::printf(v.what());
    } catch (std::exception &error){
        std::printf(error.what());
    }
    std::printf("Fin del intento marry3\n\n");


    std::printf("Fin de las pruebas\n");
    return 0;
}
