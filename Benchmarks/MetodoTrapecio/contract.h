#ifndef CONTRACT_H
#define CONTRACT_H

#include <string>
#include <exception>
#include <vector>
#include <iostream>
#include <functional>
#include <memory>
#include <utility>

namespace contract {

    /*!
     * \brief The violation_error class
     */
    class violation_error: public std::exception{

    public:
        violation_error(std::string msg);
        virtual const char* what() const noexcept;
        virtual ~violation_error() noexcept {}
    protected:
        std::string error_msg;
    };


    #define INVARIANT(bool_exp) { \
    [=]() noexcept{return bool_exp ;} \
    }

    ///TODO: avanzar con la informacion extra del invariante
    // struct invariant_info {
    //     std::function<bool()> p_lambda;
    //     std::string msg;
    //     // id de la clase
    // };

    template<class T>
    class Invariant{
        std::vector<std::function<bool()> > invariants;
    public:
        Invariant() { invariants.push_back([](){return true;});}
        inline void operator()(bool logic_exp, const std::string msg);

    protected:
        void add_invariant(std::function<bool()> p_lamda){
            invariants.push_back(p_lamda);
        }

        void check_invariant()
        {
            // std::printf("ingresa a check_invariant()\n");

            for (auto &inv : invariants){
                // std::printf("Llamada al invariante: ");
                // bool pr = inv();
                // std::cout<<pr;
                // std::printf("\n");
                if (!inv()) {
                    throw violation_error("ERROR: Contract violation\n");
                }
            }

        }

    };

    //---------------------
    // Opción con funciones
    //---------------------

    //TODO: discutir precondition/require postcondition/ensure
    void assure(const bool logic_exp, const std::string msg=" ");

    void precondition(const bool logic_exp, const std::string msg=" ");

    void postcondition(const bool logic_exp, const std::string msg=" ");

    //---
    //END
    //---

    //-----------------
    //Opción con macros
    //-----------------
    #define ASSURE(logic_exp, msg) \
        if (!logic_exp) { \
            throw contract::violation_error(msg); \
        }

    #define REQUIRE(logic_exp, msg) ASSURE(logic_exp, msg)

    #define ENSURE(logic_exp, msg) ASSURE(logic_exp, msg)
    //---
    //END
    //---


    //-----------------
    //Opción con clases
    //-----------------
    class Contract {
    public:
        Contract() {}

        void operator()(const bool logic_exp, const std::string msg = " ");
    };

    extern Contract precond, postcond;
    //---
    //END
    //---

}

#endif // CONTRACT_H
