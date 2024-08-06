#include "person.h"

/*
     * Variable para definir el tipo de pre y post a usar
     * Tipos admitidos:
     *  - macro
     *  - funcion
     *  - clase
     */
// #define ASSERT_MACRO
#define ASSERT_FUNCTION
// #define ASSERT_CLASS

/*
 * Variable para definir como se añaden los invariantes
 * Tipos admitidos:
 *  - macro
 *  - lambda
*/
// #define INVARIANT_MACRO
#define INVARIANT_LAMBDA



Person::Person() {
#ifdef INVARIANT_MACRO
    add_invariant(INVARIANT(
        is_married? (spouse != nullptr) && (spouse->spouse == this) : (spouse == nullptr))
                  );
#elif defined(INVARIANT_LAMBDA)
    add_invariant([&](){
        return (is_married? (spouse != nullptr) && (spouse->spouse == this) : (spouse == nullptr));
    });
#else
    std::printf("No se agregaron invariantes\n");
#endif

    check_invariant();
}

void Person::marry_1(Person &p)
{
#ifdef ASSERT_FUNCTION
    /// ---------------------------
    /// Precondiciones como función
    /// ---------------------------
    std::printf("Se checkean pre como función\n");
    contract::precondition((&p != nullptr), "P es null\n");
    contract::precondition(!is_married, "Ya está casado\n");
    contract::precondition(!p.is_married, "P ya está casado\n");
    /// ---
    /// END
    /// ---
#elif defined(ASSERT_MACRO)
    /// -------------------------
    /// Precondiciones como macro
    /// -------------------------
    std::printf("Se checkean pre como macro\n");
    REQUIRE((&p != nullptr), "P es null\n");
    REQUIRE(!is_married, "Ya está casado\n");
    REQUIRE(!p.is_married, "P ya está casado\n");
    /// ---
    /// END
    /// ---
#elif defined(ASSERT_CLASS)
    /// -------------------------
    /// Precondiciones como clase
    /// -------------------------
    std::printf("Se checkean pre como clase\n");
    contract::precond(&p != nullptr, "P es null\n");
    contract::precond(!is_married, "Ya está casado\n");
    contract::precond(!p.is_married, "P ya está casado\n");
    /// ---
    /// END
    /// ---
#else
    std::printf("No se checkean precondiciones\n");
#endif

    /// --------------------
    /// Cuerpo de la función
    /// --------------------
    check_invariant();
    spouse = &p;
    is_married = true;
    p.marry_1(*this);
    check_invariant();
    /// ---
    /// END
    /// ---

    /// -------------------
    /// Ensure como función
    /// -------------------
#ifdef ASSERT_FUNCTION
    std::printf("Se checkean post como funcion\n");
    contract::postcondition(is_married, "No está casado\n");
    contract::postcondition(spouse == &p, "Spouse != p\n");
    /// ---
    /// END
    /// ---
#elif defined(ASSERT_MACRO)
    /// -----------------
    /// Ensure como macro
    /// -----------------
    std::printf("Se checkean post como macro\n");
    ENSURE(is_married, "No está casado\n");
    ENSURE((spouse == &p), "Spouse != p\n");
    /// ---
    /// END
    /// ---
#elif defined(ASSERT_CLASS)
    /// -----------------
    /// Ensure como clase
    /// -----------------
    std::printf("Se checkean post como clase\n");
    contract::postcond(is_married, "No está casado\n");
    contract::postcond(spouse == &p, "Spouse != p\n");
    /// ---
    /// END
    /// ---
#else
    std::printf("No se checkean postcondiciones\n");
#endif
}

void Person::marry_2(Person &p)
{
    /// ---------------------------
    /// Precondiciones como función
    /// ---------------------------
#ifdef ASSERT_FUNCTION
    std::printf("Se checkean pre como función\n");
    contract::precondition((&p != nullptr), "P es null\n");
    contract::precondition(!is_married, "Ya está casado\n");
    contract::precondition(!p.is_married, "P ya está casado\n");
    /// ---
    /// END
    /// ---
#elif defined(ASSERT_MACRO)
    /// -------------------------
    /// Precondiciones como macro
    /// -------------------------
    std::printf("Se checkean pre como macro\n");
    REQUIRE((&p != nullptr), "P es null\n");
    REQUIRE(!is_married, "Ya está casado\n");
    REQUIRE(!p.is_married, "P ya está casado\n");
    /// ---
    /// END
    /// ---
#elif defined(ASSERT_CLASS)
    /// -------------------------
    /// Precondiciones como clase
    /// -------------------------
    std::printf("Se checkean pre como clase\n");
    contract::precond(&p != nullptr, "P es null\n");
    contract::precond(!is_married, "Ya está casado\n");
    contract::precond(!p.is_married, "P ya está casado\n");
    /// ---
    /// END
    /// ---
#else
    std::printf("No se checkean precondiciones\n");
#endif

    /// --------------------
    /// Cuerpo de la función
    /// --------------------
    check_invariant();
    p.marry_2(*this);
    spouse = &p;
    is_married = true;
    check_invariant();
    /// ---
    /// END
    /// ---

#ifdef ASSERT_FUNCTION
    /// -------------------
    /// Ensure como función
    /// -------------------
    std::printf("Se checkean post como funcion\n");
    contract::postcondition(is_married, "No está casado\n");
    contract::postcondition(spouse == &p, "Spouse != p\n");
    /// ---
    /// END
    /// ---
#elif defined(ASSERT_MACRO)
    /// -----------------
    /// Ensure como macro
    /// -----------------
    std::printf("Se checkean post como macro\n");
    ENSURE(is_married, "No está casado\n");
    ENSURE((spouse == &p), "Spouse != p\n");
    /// ---
    /// END
    /// ---
#elif defined(ASSERT_CLASS)
    /// -----------------
    /// Ensure como clase
    /// -----------------
    std::printf("Se checkean post como clase\n");
    contract::postcond(is_married, "No está casado\n");
    contract::postcond(spouse == &p, "Spouse != p\n");
    /// ---
    /// END
    /// ---
#else
   std::printf("No se checkean postcondiciones\n");
#endif
}

void Person::marry_3(Person &p)
{
    /// ---------------------------
    /// Precondiciones como función
    /// ---------------------------
#ifdef ASSERT_FUNCTION
    std::printf("Se checkean pre como función\n");
    contract::precondition((&p != nullptr), "P es null\n");
    contract::precondition(!is_married, "Ya está casado\n");
    contract::precondition(!p.is_married, "P ya está casado\n");
    /// ---
    /// END
    /// ---
#elif defined(ASSERT_MACRO)
    /// -------------------------
    /// Precondiciones como macro
    /// -------------------------
    std::printf("Se checkean pre como macro\n");
    REQUIRE((&p != nullptr), "P es null\n");
    REQUIRE(!is_married, "Ya está casado\n");
    REQUIRE(!p.is_married, "P ya está casado\n");
    /// ---
    /// END
    /// ---
#elif defined(ASSERT_CLASS)
    /// -------------------------
    /// Precondiciones como clase
    /// -------------------------
    std::printf("Se checkean pre como clase\n");
    contract::precond(&p != nullptr, "P es null\n");
    contract::precond(!is_married, "Ya está casado\n");
    contract::precond(!p.is_married, "P ya está casado\n");
    /// ---
    /// END
    /// ---
#else
    std::printf("No se checkean precondiciones\n");
#endif
    /// --------------------
    /// Cuerpo de la función
    /// --------------------
    check_invariant();
    get_engaged(p);
    p.get_engaged(*this);
    check_invariant();
    /// ---
    /// END
    /// ---


#ifdef ASSERT_FUNCTION
    /// -------------------
    /// Ensure como función
    /// -------------------
    std::printf("Se checkean post como funcion\n");
    contract::postcondition(is_married, "No está casado\n");
    contract::postcondition(spouse == &p, "Spouse != p\n");
    /// ---
    /// END
    /// ---
#elif defined(ASSERT_MACRO)
    /// -----------------
    /// Ensure como macro
    /// -----------------
    std::printf("Se checkean post como macro\n");
    ENSURE(is_married, "No está casado\n");
    ENSURE((spouse == &p), "Spouse != p\n");
    /// ---
    /// END
    /// ---
#elif defined(ASSERT_CLASS)
    /// -----------------
    /// Ensure como clase
    /// -----------------
    std::printf("Se checkean post como clase\n");
    contract::postcond(is_married, "No está casado\n");
    contract::postcond(spouse == &p, "Spouse != p\n");
    /// ---
    /// END
    /// ---
#else
        std::printf("No se checkean postcondiciones\n");
#endif

}

void Person::get_engaged(Person &p)
{
    // sin precondiciones, ya que se invoca solo desde el método marry3
    spouse = &p;
    is_married = true;
    // no se chequea invariante aquí

    /// -------------------
    /// Ensure como funcion
    /// -------------------
#ifdef ASSERT_FUNCTION
    std::printf("Se checkean post como funcion\n");
    contract::postcondition(spouse == &p, "Spouse != p\n");
    contract::postcondition(is_married, "No se casó\n");
    /// ---
    /// END
    /// ---
#elif defined(ASSERT_MACRO)
    /// -----------------
    /// Ensure como macro
    /// -----------------
    std::printf("Se checkean post como macro\n");
    ENSURE((spouse == &p), "Spouse != p\n");
    ENSURE(is_married, "No se casó\n");
    /// ---
    /// END
    /// ---
#elif defined(ASSERT_CLASS)
    /// -----------------
    /// Ensure como clase
    /// -----------------
    std::printf("Se checkean post como clase\n");
    contract::postcond(spouse == &p, "Spouse != p\n");
    contract::postcond(is_married, "No se casó\n");
    /// ---
    /// END
    /// ---
#endif


}
