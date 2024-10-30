#include <iostream>

// using namespace std;
// preprocessor directive. Preprocessor replaces all 'MACROS' used in the file with predefined value (substitution text). Should not be used in the modern C++
#define MACROS "Hello from macros!"
#define MACROS2 // could be used 


void printPassedInt(int num) {
	std::cout << num << "\n";
	std::cout << MACROS << "\n";

}