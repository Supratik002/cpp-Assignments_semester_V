#include <iostream>
#include <cmath>

double roundtoKthplace(double number, int k) {
    double f = k;
    return std::round(number* f) / f;
}

int main() {
    double n;
    int k;
    std::cout << "Enter a real number: ";
    std::cin >> n;
    std::cout << "Enter a positive integer k(multiple of 10): ";
    std::cin >> k;
    double roundNumber = roundtoKthplace(n, k);
    std::cout << "Rounded number: " << roundNumber <<"\n" ;
    return 0;
}
