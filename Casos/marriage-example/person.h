#ifndef PERSON_H
#define PERSON_H
#include "../contract-lib/contract.h"

class Person : protected contract::Invariant<Person>
{

public:
    Person();
    void marry_1(Person &p);
    void marry_2(Person &p);
    void marry_3(Person &p);

private:
    Person *spouse = nullptr;
    bool is_married = false;

    void get_engaged(Person &p);

};

#endif // PERSON_H
