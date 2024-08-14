#include <iostream>
int printBinary(int number, int bits) {
    char binary[bits];
    for (int i = 0; i < bits; ++i) {
        binary[i] = '0';
    }
    for (int i = bits - 1; number > 0 && i >= 0; --i) {
        binary[i] = (number % 2) ? '1' : '0'; 
        number /= 2; 
    }
    for (int i = 0; i < bits; ++i) {
        std::cout << binary[i];
    }
    return 0;
}
int main() {
    int positiveInteger, negativeInteger;
    std::cout << "Enter a positive integer: ";
    std::cin >> positiveInteger;
    std::cout << "Enter a negative integer: ";
    std::cin >> negativeInteger;
    std::cout << "\nPositive Integer: " << positiveInteger<<"\n";
    std::cout << "Binary Representation (8 bits): ";
    printBinary(positiveInteger, 8);
    std::cout << "Negative Integer: " << negativeInteger << "\n";
    std::cout << "Binary Representation (8 bits): ";
    printBinary(negativeInteger + 256, 8);
    
   }

