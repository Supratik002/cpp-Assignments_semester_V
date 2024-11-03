#include <iostream>

class Tiny {
    char v; // internal storage for the 6-bit integer (0-63)

    // Helper function to assign value with range checking
    void assign(int i) {
        if (i < 0 || i > 63) // Check 6-bit range (0-63)
            throw Bad_range();
        v = static_cast<char>(i); // Assign if within range
    }

public:
    // Exception class for out-of-range errors
    class Bad_range {};

    // Constructor to initialize with an integer, with range checking
    Tiny(int i = 0) {
        assign(i); // Perform range check and assign
    }

    // Copy constructor
    Tiny(const Tiny& other) : v(other.v) {}

    // Conversion operator to allow Tiny to be used as an int
    operator int() const {
        return v;
    }

    // Overload assignment operator for assigning an int to Tiny
    Tiny& operator=(int i) {
        assign(i); // Perform range check
        return *this;
    }

    // Overload assignment operator for assigning a Tiny to Tiny
    Tiny& operator=(const Tiny& other) {
        v = other.v; // Direct assignment, no range check needed
        return *this;
    }

    // Overload addition operator with int, return result as Tiny
    Tiny operator+(int i) const {
        Tiny result(*this); // Start with the current value
        result.assign(v + i); // Add and range-check
        return result;
    }

    // Overload addition operator with another Tiny, return result as Tiny
    Tiny operator+(const Tiny& t) const {
        return *this + static_cast<int>(t); // Use int version
    }

    // Overload subtraction operator with int, return result as Tiny
    Tiny operator-(int i) const {
        Tiny result(*this);
        result.assign(v - i); // Subtract and range-check
        return result;
    }

    // Overload subtraction operator with another Tiny, return result as Tiny
    Tiny operator-(const Tiny& t) const {
        return *this - static_cast<int>(t); // Use int version
    }

    // Overload addition assignment operator with int
    Tiny& operator+=(int i) {
        assign(v + i);
        return *this;
    }

    // Overload addition assignment operator with another Tiny
    Tiny& operator+=(const Tiny& t) {
        return *this += static_cast<int>(t); // Use int version
    }

    // Overload subtraction assignment operator with int
    Tiny& operator-=(int i) {
        assign(v - i);
        return *this;
    }

    // Overload subtraction assignment operator with another Tiny
    Tiny& operator-=(const Tiny& t) {
        return *this -= static_cast<int>(t); // Use int version
    }
};

int main() {
    try {
        Tiny c1 = 2; // Perform range check
        Tiny c2 = 62; // Perform range check
        Tiny c3 = c2 - c1; // c3 = 60;
        Tiny c4 = c3; // no range check required
        int i = c1 + c2; // i = 64
        c1 = c1 + c2; // range error: c1 can’t be 64
        i = c3 - 64; // i = -4
        c2 = c3 - 64; // range error: c2 can’t be -4
        c3 = c4; // no range check required
    } catch (const Tiny::Bad_range&) {
        std::cerr << "Range error: value out of range for Tiny" << std::endl;
    }
}
