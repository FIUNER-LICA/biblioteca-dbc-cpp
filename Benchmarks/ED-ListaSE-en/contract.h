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
     * \brief The violation_error class represents an exception thrown when a violation occurs.
     */
    class violation_error: public std::exception{

    public:
        /*!
         * \brief Construct a violation_error object with the specified message.
         *
         * \param msg The error message associated with the violation.
         */
        violation_error(std::string msg);

        /*!
         * \brief Returns a string describing the exception.
         *
         * \return A pointer to a string with the description of the exception.
         */
        virtual const char* what() const noexcept;

        /*!
         * \brief Destructor for violation_error.
         */
        virtual ~violation_error() noexcept {}
    protected:
        /*!
         * \brief Error message associated with the violation.
         */
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

    /*!
     * \brief The Invariant class
     */
    class Invariant{
        /*!
         * \brief Array of invariants of a certain class.
         */
        std::vector<std::function<bool()> > invariants;

    public:
        /*!
         * \brief Constructor for Invariant.
         */
        Invariant() { invariants.push_back([](){return true;});}

        /*!
         * \brief Overloaded function call operator.
         *
         * This function overloads the `()` operator to evaluate a logical expression and,
         * depending on its value, handle an associated message.
         *
         * \param logic_exp Logical expression to evaluate.
         * \param msg Message to handle if \c logic_exp is \c false
         */
        inline void operator()(bool logic_exp, const std::string msg);

    protected:
        /*!
         * \brief Append an invariant to \c invariants
         *
         * This method appends an \c function<bool()> to the vector
         * of invariants.
         *
         * \param p_lambda The \c function<bool()> to append.
         */
        void add_invariant(std::function<bool()> p_lambda){
            invariants.push_back(p_lambda);
        }

        /*!
         * \brief Check that there is no invariant violation.
         */
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

    /*!
     * \brief Auxiliar function to check pre and postconditions.
     *
     * Auxiliar function used by \c precondition and \c postcondition
     * to evaluate a certain \c logic_exp and throw an exception in
     * case its \c false.
     *
     * \param logic_exp Logic expression to evaluate.
     * \param msg Message to handle if \c logic_exp is \c false
     */
    void assure(const bool logic_exp, const std::string msg=" ");

    /*!
     * \brief Function to evaluate preconditions.
     *
     * Evaluate a certain \c logic_exp and throw an exception in
     * case its `false`.
     *
     * \param logic_exp Logic expression to evaluate.
     * \param msg Message to handle if \c logic_exp is `false`
     */
    void precondition(const bool logic_exp, const std::string msg=" ");

    /*!
     * \brief Function to evaluate postconditions.
     *
     * Evaluate a certain \c logic_exp and throw an exception in
     * case its \c false.
     *
     * \param logic_exp Logic expression to evaluate.
     * \param msg Message to handle if \c logic_exp is \c false
     */
    void postcondition(const bool logic_exp, const std::string msg=" ");

    //---
    //END
    //---

    //-----------------
    //Opción con macros
    //-----------------
    /*!
     * \def ASSURE(logic_exp, msg)
     * \brief Auxiliar macro to check pre and postconditions.
     *
     * Auxiliar macro used by \c REQUIRE and \c ENSURE
     * to evaluate a certain \c logic_exp and throw an exception in
     * case its `false`.
     *
     * \param logic_exp Logic expression to evaluate.
     * \param msg Message to handle if \c logic_exp is \c false
     */
    #define ASSURE(logic_exp, msg) \
        if (!logic_exp) { \
            throw contract::violation_error(msg); \
        }

    /*!
     * \def REQUIRE(logic_exp, msg)
     * \brief Macro to evaluate preconditions.
     *
     * Evaluate a certain \c logic_exp and throw an exception in
     * case its `false`.
     *
     * \param logic_exp Logic expression to evaluate.
     * \param msg Message to handle if \c logic_exp is \c false
     */
    #define REQUIRE(logic_exp, msg) ASSURE(logic_exp, msg)


    /*!
     * \def ENSURE(logic_exp, msg)
     * \brief Macro to evaluate postconditions.
     *
     * Evaluate a certain \c logic_exp and throw an exception in
     * case its \c false.
     *
     * \param logic_exp Logic expression to evaluate.
     * \param msg Message to handle if \c logic_exp is \c false
     */
    #define ENSURE(logic_exp, msg) ASSURE(logic_exp, msg)
    //---
    //END
    //---


    //-----------------
    //Opción con clases
    //-----------------
    /*!
     * \brief The Contract class
     *
     * This class is used to handle logical expressions and throw exceptions
     * if certain conditions are not met. It provides an overloaded function call
     * operator to facilitate this functionality.
     */
    class Contract {
    public:
        /*!
         * \brief Default constructor for Contract.
         *
         * Initializes a new instance of the Contract class.
         */
        Contract() {}

        /*!
         * \brief Overloaded function call operator.
         *
         * This operator evaluates a logical expression and throws an exception
         * with a specified message if the expression is false.
         *
         * \param logic_exp The logical expression to evaluate. If \c logic_exp is false, an exception is thrown.
         * \param msg The message to include with the exception if \c logic_exp is false. Defaults to an empty string.
         */
        void operator()(const bool logic_exp, const std::string msg = " ");
    };

    extern Contract precond, postcond;
    //---
    //END
    //---

}

#endif // CONTRACT_H
