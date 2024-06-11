#ifndef CODE_TESTS_H
#define CODE_TESTS_H

#include <iostream>
#include <vector>
#include <list>

void code_test_1() {
    using namespace std;
    struct A { int foo, bar; };
    struct B {
        A a;
        A *operator->() {
            cout << "Se llama a operator-> de B" << endl;
            return &a; }
    };
    struct C {
        B b;
        B operator->() {
            cout << "Se llama a operator-> de C" << endl;
            return b; }
    };
    struct D {
        C c;
        C operator->() {
            cout << "Se llama a operator-> de D" << endl;
            return c; }
    };
    D d;
    d->bar;
}

void code_test_2() {
    std::vector<int> vec{1,2,3,4};
    std::vector<int> vec2{10,20,30,40};
    std::vector<int>::iterator it = vec2.begin();
    vec.insert(it, 5); // NOTE: UB

    std::cout << "vec.size(): " << vec.size() << std::endl;
    std::cout << "vec2.size(): " << vec2.size() << std::endl;
    for(auto value: vec)
        std::cout << value << " ";
    std::cout << std::endl;
}

void code_test_3() {
    std::list<int> lis{1,2,3,4};
    std::list<int> lis2{10,20,30,40};
    std::list<int>::iterator it = lis2.begin();
    ++it;
    lis.insert(it, 5); // NOTE: UB

    std::cout << "lis.size(): " << lis.size() << std::endl;
    std::cout << "lis2.size(): " << lis2.size() << std::endl;

    std::cout << "lis: ";
    for(auto value: lis)
        std::cout << value << " ";
    std::cout << std::endl;

    std::cout << "lis2: ";
    for(auto value: lis2)
        std::cout << value << " ";
    std::cout << std::endl;
}

#endif // CODE_TESTS_H
