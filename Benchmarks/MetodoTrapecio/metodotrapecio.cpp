#include "metodotrapecio.h"

#include <iostream>



MetodoTrapecio::MetodoTrapecio(double _a, double _b, int _n)
{
#ifdef INVARIANT_MACRO
    add_invariant(INVARIANT(
        a < b));
#elif defined(INVARIANT_LAMBDA)
    add_invariant([&](){
        return a < b;
    });
#endif

    a = _a;
    b = _b;
    n = _n;

    check_invariant();
}

double MetodoTrapecio::calcular_integral(double (*func)(double))
{
    /// ---------------------------
    /// Precondiciones como función
    /// ---------------------------
    #ifdef ASSERT_FUNCTION
    contract::precondition(std::is_invocable<decltype(func), double>::value, "La funcion no es invocable");
    /// ---
    /// END
    /// ---
    #elif defined(ASSERT_MACRO)
    /// -------------------------
    /// Precondiciones como macro
    /// -------------------------
    REQUIRE((std::is_invocable<decltype(func), double>::value), "La funcion no es invocable");
    /// ---
    /// END
    /// ---
    #elif defined(ASSERT_CLASS)
    /// -------------------------
    /// Precondiciones como clase
    /// -------------------------
    contract::precond(std::is_invocable<decltype(func), double>::value, "La funcion no es invocable");
    /// ---
    /// END
    /// ---
    #else
    //std::printf("No se checkean precondiciones\n");
    #endif

    double h = (b - a) / n;
    double suma = 0.5 * (func(a) + func(b));
    for (int i = 1 ; i < n ; ++i)
    {
        // suma += func(a + i * h);
        suma += step(func, i, h);
    }
    suma = suma * h;
    #ifdef ASSERT_FUNCTION
    /// -------------------
    /// Ensure como función
    /// -------------------
    contract::postcondition(typeid(suma) == typeid(double), "La suma no es de tipo double");
    //contract::postcondition(suma == 0.5 * (func(a) + func(b)) * (b - a), "El resultado no cumple con la fórmula del método del trapecio");
    /// ---
    /// END
    /// ---
    #elif defined(ASSERT_MACRO)
    /// -----------------
    /// Ensure como macro
    /// -----------------
    ENSURE((typeid(suma) == typeid(double)), "La suma no es de tipo double");
    //ENSURE(suma == 0.5 * (func(a) + func(b)) * (b - a), "El resultado no cumple con la fórmula del método del trapecio");
    /// ---
    /// END
    /// ---
    #elif defined(ASSERT_CLASS)
    /// -----------------
    /// Ensure como clase
    /// -----------------
    contract::postcond(typeid(suma) == typeid(double), "La suma no es de tipo double");
    //contract::postcond(suma == 0.5 * (func(a) + func(b)) * (b - a), "El resultado no cumple con la fórmula del método del trapecio");
    /// ---
    /// END
    /// ---
    #else
    //std::printf("No se checkean postcondiciones\n");
    #endif
    check_invariant();
    return suma;
}

double MetodoTrapecio::step(double (*func)(double), double x, double h)
{
    /// ---------------------------
    /// Precondiciones como función
    /// ---------------------------
    #ifdef ASSERT_FUNCTION
    contract::precondition(x <= n, "x excede extremo superior.");
    contract::precondition(x >= 1, "x excede extremo inferior.");
    contract::precondition(h > 0, "paso negativo");
    /// ---
    /// END
    /// ---
    #elif defined(ASSERT_MACRO)
    /// -------------------------
    /// Precondiciones como macro
    /// -------------------------
    REQUIRE((x <= n), "x excede extremo superior.");
    REQUIRE((x >= 1), "x excede extremo inferior.");
    REQUIRE((h > 0), "paso negativo");
    /// ---
    /// END
    /// ---
    #elif defined(ASSERT_CLASS)
    /// -------------------------
    /// Precondiciones como clase
    /// -------------------------
    contract::precond(x <= n, "x excede extremo superior.");
    contract::precond(x >= 1, "x excede extremo inferior.");
    contract::precond(h > 0, "paso negativo");
    /// ---
    /// END
    /// ---
    #else
       // std::printf("No se checkean precondiciones\n");
    #endif

    double calc = func(a + x * h);

    #ifdef ASSERT_FUNCTION
    /// -------------------
    /// Ensure como función
    /// -------------------
    contract::postcondition(typeid(calc) == typeid(double), "El cálculo no es de tipo double");
    /// ---
    /// END
    /// ---
    #elif defined(ASSERT_MACRO)
    /// -----------------
    /// Ensure como macro
    /// -----------------
    ENSURE((typeid(calc) == typeid(double)), "El cálculo no es de tipo double");
    /// ---
    /// END
    /// ---
    #elif defined(ASSERT_CLASS)
    /// -----------------
    /// Ensure como clase
    /// -----------------
    contract::postcond(typeid(calc) == typeid(double), "El cálculo no es de tipo double");
    /// ---
    /// END
    /// ---
    #else
    //std::printf("No se checkean postcondiciones\n");
    #endif
    check_invariant();
    return calc;
}
