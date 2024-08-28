/*Result After Function Execution*:
   After the function f1 is executed, the array m will have its values updated as follows:
   - All elements in the array are incremented by 2:
     
     3   4   5   6   7
     13  14  15  16  17
     23  24  25  36  27
*/

#include <iostream>

void f1(int m[][5], int dim1) {
    for(unsigned int i = 0; i < dim1; i++)
        for(unsigned int j = 0; j < 5; j++)
            m[i][j] = m[i][j] + 2;  // Increment each element by 2
}

int main() {
    // Initialize a 2D array.
    int m[3][5] = {{1, 2, 3, 4, 5}, {11, 12, 13, 14, 15}, {21, 22, 23, 34, 25}};
    
    // Call function f1 to modify the array.
    f1(m, 3);
    
    // Print the modified array.
    for(unsigned int i = 0; i < 3; i++) {
        for(unsigned int j = 0; j < 5; j++)
            std::cout << m[i][j] << " ";
        std::cout << "\n";
    }
}

/*Validity of Passing a 2D Array to a Function Without the First Dimension

In C++, when passing a 2D array to a function, we must specify the size of all dimensions except the first one. Because:
1. Array Memory Layout:
   - A 2D array is stored in memory as a contiguous block of data. For example, the array int m[3][5] is stored as a single block of 15 integers in row-major order.
   - To correctly index into this block of memory, the compiler needs to know the size of each row (i.e., the number of columns). This is why we must specify the size of all dimensions except the first one when passing a 2D array to a function.

Why Can't the First Dimension Be Omitted?
   - The first dimension (number of rows) can be omitted because when we pass an array to a function, what is actually passed is a pointer to the first element of the array.
   - For a 2D array, this pointer points to the first row, and the array type decays into a pointer to an array of integers (e.g., int (*)[5] for a 5-column 2D array).
   - Since the function already knows that each row contains 5 integers, it can correctly index into the 2D array using this information.*/


   
