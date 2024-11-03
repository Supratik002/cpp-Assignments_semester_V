#include <iostream>

struct X {
    int i;
    
    X(int i) : i(i) {} // Constructor
    
    X operator+(int val) const { // X + int
        return X(i + val);
    }
};

struct Y {
    int i;
    
    // Constructor allowing Y to be initialized from an X
    Y(X x) : i(x.i) {}

    Y(int i = 0) : i(i) {} // Constructor from int
    
    Y operator+(X x) const { // Y + X
        return Y(i + x.i);
    }
    
    // Overloaded + operator to add two Y objects
    Y operator+(const Y& other) const {
        return Y(i + other.i);
    }
    
    operator int() const { // Y to int
        return i;
    }
};

// Operator overloading for `X * Y`
X operator*(X x, Y y) {
    return X(x.i * y.i);
}

// Function f taking an X parameter
int f(X x) {
    return x.i;
}

int main() {
    X x = 1;
    Y y = x;  // Convert X to Y

    int i = 2;
    
    // Evaluate and print each expression
    std::cout << "i + 10 = " << (i + 10) << std::endl;
    std::cout << "y + 10 = " << (static_cast<int>(y) + 10) << std::endl;
    std::cout << "y + 10 * y = " << (static_cast<int>(y) + 10 * static_cast<int>(y)) << std::endl;
    std::cout << "x + y + i = " << ((x + y) + i).i << std::endl;
    std::cout << "x * x + i = " << (x * Y(x) + i).i << std::endl;
    std::cout << "f(7) = " << f(7) << std::endl;
    std::cout << "f(y) = " << f(X(y)) << std::endl;
    std::cout << "y + y = " << (y + y).i << std::endl;  // Fixed by using `Y::operator+(Y)`
    std::cout << "106 + y = " << (106 + static_cast<int>(y)) << std::endl;

    return 0;
}
/*
    In the code, the following conversions are used throughout the expressions in main():
    
    1. Implicit Conversion from int to X:
      Expression: X x = 1;
      Conversion: The integer 1 is implicitly converted to an X object using the X(int) constructor.
    2. Implicit Conversion from X to Y:
      Expression: Y y = x;
      Conversion: The X object x is converted to a Y object using the Y(X) constructor.
    3. Conversion from Y to int:
      Expression: y + 10;
      Conversion: The Y object y is converted to int using the operator int().
    4. Conversion from Y to int for multiplication:
      Expression: 10 * y;
      Conversion: The Y object y is converted to int using operator int().
    5. Conversion from Y to int in an addition with an integer:
      Expression: static_cast<int>(y) + 10
      Conversion: The Y object y is explicitly converted to int using static_cast<int>(y).
    6. Implicit Conversion from Y to int:
      Expression: f(y);
      Conversion: The Y object y is converted to int using operator int() before being passed to f(X).
    7. Implicit Conversion from Y to int in an addition:
      Expression: 106 + y;
      Conversion: The Y object y is converted to int using operator int() for the addition.
    8. Implicit Conversion from X to Y for multiplication:
      Expression: x * Y(x);
      Conversion: The second x is explicitly converted to a Y object using the Y(X) constructor.
    9. Addition of Two Y Objects:
      Expression: y + y;
      Conversion: No conversion is needed here since both operands are of type Y, and the Y::operator+(Y) is called.
  */
