
#include <iostream>
//Implementation using Global Variable
int callCount = 0;
void countCalls() {
    callCount++;
    std::cout << "I have been called " << callCount << " times" << std::endl;
}
//Implementation using a Local Static Variable
void countCalls() {
    static int callCount = 0;  // Local static variable to keep track of the count
    callCount++;
    std::cout << "I have been called " << callCount << " times" << std::endl;
}
int main() {
    for (int i = 0; i < 10; ++i) {
        countCalls();
    }
    return 0;
}
/*Why Can't You Use a Local Variable?

You can't use a regular local variable (non-static) to achieve this because a local variable is re-initialized every time the function is called.*/

/*Which Approach is More Appropriate?

The *local static variable* approach is more appropriate for this scenario because it confines the "callCount" variable to the function's scope, avoiding potential issues with global variables such as unintentional modifications from other parts of the program. This makes the code easier to understand and maintain.*/

