#include <QCoreApplication>
#include <iostream>
#include <iomanip>
#include <algorithm>

#include "singly_linked_list.h"
#include "code_tests.h"  // TODO: erase inclusion

void show_list(SLList<int> &p_list);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "Program begins." << std::endl;

    { // NOTE: to see Node destructor calls.
        std::cout << "A list is created." << std::endl;
        SLList<int> int_list;

        std::cout << "Adding some values to the list" << std::endl;
        int_list.insert(5);
        int_list.insert(2);
        int_list.insert(7);

        show_list(int_list);    // 5 2 7

        std::cout << "Adding some values in the middle" << std::endl;
        ListIterator<int> it = int_list.begin();
        ++it;
        int_list.insert(8, it);
        show_list(int_list);    // 5 8 2 7
        int_list.insert(9, it); // The iterator moves with the internal node.
        show_list(int_list);    // 5 8 9 2 7
        ++it;
        int_list.insert(1, it); // Insert before the last posistion
        show_list(int_list);    // 5 8 9 2 1 7
        // Wrong code:
        //  ++it;  // null iterator... the end has been reached
        //  int_list.insert(0, it); // Insert before the last posistion
        int_list.insert(3); // insert after the last position
        show_list(int_list);    // 5 8 9 2 1 7 3

        // The "find" method
        std::cout << "Finding a present value (2) with find: " << std::endl;
        bool found = int_list.find(2);
        std::cout << std::boolalpha;
        std::cout << "\tFinding result: " << found << std::endl;
        std::cout << (found?"\tThe value 2 is present.":"\tThe value 2 is not present");
        std::cout << std::endl;

        std::cout << "Finding a NOT present value (-4) with find: " << std::endl;
        found = int_list.find(-4);
        std::cout << "\tFinding result: " << found << std::endl;
        std::cout << (found?"\tThe value -4 is present.":"\tThe value -4 is not present");
        std::cout << std::endl;

        // The "find2" method
        std::cout << "Finding a present value (2) with find2: " << std::endl;
        ListIterator<int> iter = int_list.find2(2);
        ListIterator<int> null_iter;
        std::cout << "\tFinding result: " << (iter != null_iter) << std::endl;
        std::cout << ((iter != null_iter)?"\tThe value 2 is present.":"\tThe value 2 is not present");
        std::cout << std::endl;

        std::cout << "Finding a NOT present value (-4) with find2: " << std::endl;
        iter = int_list.find2(-4);
        std::cout << "\tFinding result: " << (iter != null_iter) << std::endl;
        std::cout << ((iter != null_iter)?"\tThe value -4 is present.":"\tThe value -4 is not present");
        std::cout << std::endl;

        std::cout << "Removing some values" << std::endl;
        int_list.remove(5); // 5 8 9 2 1 7 3 --> 8 9 2 1 7 3
        show_list(int_list);
        int_list.remove(3); // 8 9 2 1 7 3 --> 8 9 2 1 7
        show_list(int_list);
        int_list.remove(2); // 8 9 2 1 7 --> 8 9 1 7
        show_list(int_list);

        // *** this code block should throw exception ***
        // Null iterator is not valid in insert method
        try {
            ListIterator<int> it; // null iterator
            int_list.insert(99, it);
        }
        catch (std::invalid_argument& e) {
            std::cout << "Null iterator passed to insert method, except the list is empty: " << e.what() << std::endl;
        }
        // **********************************************

        // *** this code block should throw exception ***
        // Iterator pointing to other list is not valid in insert method
        try {
            SLList<int> other_int_list;
            other_int_list.insert(10);
            other_int_list.insert(20);
            other_int_list.insert(30);
            ListIterator<int> it = other_int_list.begin();
            int_list.insert(99, it); // it correspond to other_int_list, not int_list
        }
        catch (std::invalid_argument& e) {
            std::cout << "Iterator pointint to other list passed to insert method: " << e.what() << std::endl;
        }
        // **********************************************


        // *** this code block should throw exception ***
        // Iterator pointing to other list is not valid in insert method
        try {
            ListIterator<int> it = SLList<int>().begin(); // iterator null and to other list
            int_list.insert(99, it);
        }
        catch (std::exception& e) {
            std::cout << "Iterator null and to other list passed to insert method: " << e.what() << std::endl;
        }
        // **********************************************
    }

    std::cout << "Program ends." << std::endl;

    // TODO: erase code tests
    // code tests
    //code_test_1();
    //code_test_2();
    //code_test_3();

    return a.exec();
}

void show_list(SLList<int> &p_list) {
    // for(auto iter = p_list.begin(); iter != p_list.end(); ++iter)
    //     std::cout << (*iter) << " ";
    // std::cout << std::endl;

    // for(auto value : p_list)
    //     std::cout << value << " ";
    // std::cout << std::endl;

    std::for_each(p_list.begin(), p_list.end(), [&](int number){
        std::cout << number << " ";
    });
    std::cout << std::endl;
}
