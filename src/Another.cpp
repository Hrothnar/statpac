#include <iostream>
#include <iomanip>
#include <bitset>
#include <cmath> // For pow()

int customFunction() {
    std::cout << "The another file" << std::endl;
    return 0;
}

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