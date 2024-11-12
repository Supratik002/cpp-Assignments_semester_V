#include <iostream>
#include <fstream>
uint64_t sumCharactersInFile(const std::string& filePath) {
    uint64_t total = 0;
    char ch;
    // Open the file in text mode
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return 0;
    }
    // Read each character and add its ASCII value to total
    while (file.get(ch)) {
        total += static_cast<unsigned char>(ch);
    }
    file.close();
    return total;
}
int main() {
    std::string filePath = "my_file.txt";
    uint64_t totalSum = sumCharactersInFile(filePath);
    std::cout << "The total sum of all characters in the file is: " << totalSum << std::endl;
    return 0;
}

    
