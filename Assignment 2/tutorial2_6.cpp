#include <iostream>
#include <cstring>

// Selection sorting algorithm for integers
void sort1(int *a, int n) {
    for (unsigned int i = 0; i < n; i++)
        for (unsigned int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                std::swap(a[i], a[j]);
}

// Selection sorting algorithm for strings
void sort2(const char *a[], int n) {
    for (unsigned int i = 0; i < n - 1; i++) {
        unsigned int minIndex = i;
        for (unsigned int j = i + 1; j < n; j++) {
            // Compare strings using strcmp
            if (strcmp(a[j], a[minIndex]) < 0) {
                minIndex = j;
            }
        }
        // Swap the found minimum string with the first string
        if (minIndex != i) {
            std::swap(a[i], a[minIndex]);
        }
    }
}

int main() {
    int a[] = {-2, 3, 8, 10, 7, 56, 90};
    const char* str[] = {"hello", "world", "iacs", "raining"};

    // Sorting integers
    void (*sortInt)(int *, int);
    sortInt = &sort1;
    sortInt(a, 7); // call via function pointer

    for (unsigned int i = 0; i < 7; i++)
        std::cout << a[i] << " ";
    std::cout << "\n";
    
    // Sorting strings
    void (sortString)(const char[], int);
    sortString = &sort2;
    sortString(str, 4); // call via function pointer

    for (unsigned int i = 0; i < 4; i++)
        std::cout << str[i] << " ";
    std::cout << "\n";
    
    return 0;
}
