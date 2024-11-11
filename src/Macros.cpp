#include <iostream>

#define PRINT_JOE

int macrosUse() {

    #ifdef PRINT_JOE
        std::cout << "Joe\n"; // will be compiled since PRINT_JOE is defined
    #endif

    #ifdef PRINT_BOB // == #if defined(PRINT_BOB) (C++ style like)
        std::cout << "Bob 1\n"; // will be excluded since PRINT_BOB is not defined
    #endif

    #ifndef PRINT_BOB // == #if !defined(PRINT_BOB) (C++ style like)
        std::cout << "Bob 2\n";
    #endif

    #if 0 // Don't compile anything starting here
        std::cout << "Bob 3\n";
        std::cout << "Steve\n";
    #endif // until this point

    #if 1 // Don't compile anything starting here
        std::cout << "Bob 4\n";
        std::cout << "Steve 2\n";
    #endif // until this point

    return 0;
}