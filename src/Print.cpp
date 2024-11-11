#include <iostream>
#include "Print.h"

// using namespace std;
// preprocessor directive. Preprocessor replaces all 'MACROS' used in the file with predefined value (substitution text). Should not be used in the modern C++
#define MACROS "Hello from macros!"
#define MACROS2 // could be used 


void printPassedInt(int num) {
	std::cout << num << "\n";
	// cout << num << "\n";
	std::cout << MACROS << "\n";

}

void performStuff() {
	short num1 {2};
	int num2 {3};
	long num3 {4};
	long long num4 {5};
	unsigned short num5 {255};

	std::cout << "From 'performStuff': " << num1 << "\n";
	std::cout << "From 'performStuff': " << num2 << "\n";
	std::cout << "From 'performStuff': " << num3 << "\n";
	std::cout << "From 'performStuff': " << num4 << "\n";
	std::cout << "From 'performStuff': " << num5 << "\n";

	unsigned short x{ 65535 }; // largest 16-bit unsigned value possible
    std::cout << "x was: " << x << '\n';

    x = 65536; // 65536 is out of our range, so we get modulo wrap-around
    std::cout << "x is now: " << x << '\n';

    x = 65537; // 65537 is out of our range, so we get modulo wrap-around
    std::cout << "x is now: " << x << '\n';

}