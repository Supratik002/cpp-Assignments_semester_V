#include <iostream>
#include <fstream>
#include <vector>
uint64_t sumBytesInFile(const std::string& filePath) {
    uint64_t total = 0;
    const size_t chunkSize = 1024 * 1024; // 1MB chunk size
    std::vector<unsigned char> buffer(chunkSize);
    // Open the file in binary mode
    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return 0;
    }
    // Read and sum up bytes in chunks
    while (file) {
        file.read(reinterpret_cast<char*>(buffer.data()), chunkSize);
        std::streamsize bytesRead = file.gcount();
        for (std::streamsize i = 0; i < bytesRead; ++i) {
            total += buffer[i];
        }
    }
    file.close();
    return total;
}
int main() {
    std::string filePath = "my_file.txt";
    uint64_t totalSum = sumBytesInFile(filePath);
    std::cout << "The total sum of all bytes in the file is: " << totalSum << std::endl;
    return 0;
}
