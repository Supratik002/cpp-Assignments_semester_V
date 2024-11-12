#include <iostream>
#include <fstream>
#include <cstdint>
uint64_t sumBytesInFile(const std::string& filePath) {
    uint64_t total = 0;
    char byte;
    // Open the file in binary mode
    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return 0;
    }
    // Read each byte individually and add it to the total
    while (file.get(byte)) {
        total += static_cast<unsigned char>(byte);
    }
    file.close();
    return total;
}
int main() {
    std::string filePath = "your_large_file.bin";
    uint64_t totalSum = sumBytesInFile(filePath);
    std::cout << "The total sum of all bytes in the file is: " << totalSum << std::endl;
    return 0;
}
