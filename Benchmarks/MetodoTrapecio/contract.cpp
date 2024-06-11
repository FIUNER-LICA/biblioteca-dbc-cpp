#include "contract.h"

namespace contract {

template<class T>
void Invariant<T>::operator()(bool logic_exp, const std::string msg){
        if (not logic_exp) {
            throw violation_error(msg==""?"Error: contract violation":msg);
        }
    }

    violation_error::violation_error(std::string msg): error_msg(msg) {

    }

    const char *violation_error::what() const noexcept {
        return error_msg.c_str();
    }

    void assure(const bool logic_exp, const std::string msg)
    {
        if (not logic_exp) {
            throw violation_error(msg==" "?"violación de contrato":msg);
        }
    }

    void precondition(const bool logic_exp, const std::string msg) {
        assure(logic_exp, msg);
    }

    void postcondition(const bool logic_exp, const std::string msg) {
        assure(logic_exp, msg);
    }

    void Contract::operator()(const bool logic_exp, const std::string msg)
    {
        if (not logic_exp) {
            throw violation_error(msg==" "?"violación de contrato":msg);
        }
    }

    Contract precond, postcond;
}



