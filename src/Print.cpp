#include <iostream>
#include <cstdint> // for fast and least types

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

void showSize() {
	std::cout << "std 8:  " << sizeof(short) * 8 << " bits\n";
	std::cout << "std 16: " << sizeof(int) * 8 << " bits\n";
	std::cout << "std 32: " << sizeof(long) * 8 << " bits\n";
	std::cout << '\n';
	std::cout << "least 8:  " << sizeof(std::int_least8_t) * 8 << " bits\n";
	std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
	std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
	std::cout << '\n';
	std::cout << "fast 8:  " << sizeof(std::int_fast8_t) * 8 << " bits\n";
	std::cout << "fast 16: " << sizeof(std::int_fast16_t) * 8 << " bits\n";
	std::cout << "fast 32: " << sizeof(std::int_fast32_t) * 8 << " bits\n";
}

void doSomething() {
	bool b = {false};
	char c1 = {97};
	char c2 = {'a'};
	std::cout << std::boolalpha;
	std::cout << "The boolean is: " << b << "\n";
	std::cout << "The char is: " << c1 << "\n";
	std::cout << "The char is: " << c2 << "\n";

	std::cout << static_cast<int>(c2) << "\n";
	
	unsigned int u1 { 5 };
    // Convert value of u1 to a signed int
    int s1 { static_cast<int>(u1) };
    std::cout << s1 << '\n'; // prints 5

    int s2 { 5 };
    // Convert value of s2 to an unsigned int
    unsigned int u2 { static_cast<unsigned int>(s2) };
    std::cout << u2 << '\n'; // prints 5
}

#include <iostream>
#include <iomanip>
#include <bitset>
#include <cmath> // For pow()

void printFloatDetails(float value) {
    // Interpret the float as raw 32-bit data
    uint32_t rawBits = *reinterpret_cast<uint32_t*>(&value);

    // Extract components
    uint32_t sign = (rawBits >> 31) & 0x1;                    // Extract sign bit
    uint32_t exponent = (rawBits >> 23) & 0xFF;               // Extract 8-bit exponent
    uint32_t mantissa = rawBits & 0x7FFFFF;                   // Extract 23-bit mantissa

    // Calculate the actual exponent (subtract bias)
    int actualExponent = exponent - 127; // 127 is the bias for single precision floats

    // Display details
    std::cout << "Float value: " << value << "\n";
    std::cout << "Raw bits (hex): " << std::hex << rawBits << std::dec << "\n";
    std::cout << "Raw bits (binary): " << std::bitset<32>(rawBits) << "\n";
    std::cout << "Sign: " << sign << " (" << (sign == 0 ? "positive" : "negative") << ")\n";
    std::cout << "Exponent (raw): " << exponent << "\n";
    std::cout << "Exponent (actual): " << actualExponent << "\n";
    std::cout << "Mantissa (raw): " << std::bitset<23>(mantissa) << "\n";

    // Reconstruct the number using components
    float reconstructedValue = pow(-1, sign) * (1.0f + (float)mantissa / (1 << 23)) * pow(2, actualExponent);
    std::cout << "Reconstructed value: " << reconstructedValue << "\n";
    std::cout << "---------------------------------------\n";
}
