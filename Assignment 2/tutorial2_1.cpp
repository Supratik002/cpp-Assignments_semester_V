#include <iostream>
// Step 1: Define a typedef for the function type.
typedef void Func(char*, int&);
// Step 2: Define a typedef for a pointer to the function defined in Step 1.
typedef Func* FuncPtr;
// A sample function matching the type defined in Step 1.
void sampleFunction(char* c, int& i) {
    std::cout << "Character: " << *c << ", Integer: " << i << std::endl;
    i += 10;  // Modify the integer reference for demonstration.
}
// Step 3: Define a function that takes a pointer to the function defined in Step 1 as an argument.
void functionTakingPointer(FuncPtr fp) {
    char c = 'A';
    int i = 5;
    fp(&c, i);  // Call the function through the pointer.
}
// Step 4: Define a function that returns a pointer to the function defined in Step 1.
FuncPtr functionReturningPointer() {
    return &sampleFunction;
}
// Step 5: Define a function that takes a function pointer as an argument and returns the same pointer.
FuncPtr functionWithPointerArgument(FuncPtr fp) {
    return fp;
}
int main() {
    FuncPtr fp = &sampleFunction;
    functionTakingPointer(fp);
    FuncPtr returnedFp = functionReturningPointer();
    char c = 'B';
    int j = 20;
    returnedFp(&c, j);
    FuncPtr sameFp = functionWithPointerArgument(fp);
    sameFp(&c, j);
    return 0;
}

