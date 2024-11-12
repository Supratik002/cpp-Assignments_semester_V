#include <iostream>
#include <fstream>
#include <vector>
unsigned long long sumFileCharacters(const std::string& filename) {
    unsigned long long totalSum = 0;
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "The file " << filename << " was not found." << std::endl;
        return 0;
    }
    // Read the file in chunks to handle large files efficiently
    const std::size_t bufferSize = 1024;
    std::vector<unsigned char> buffer(bufferSize);
    while (file.read(reinterpret_cast<char*>(buffer.data()), bufferSize) || file.gcount()) {
        // Sum up all bytes read in the current chunk
        for (std::streamsize i = 0; i < file.gcount(); ++i) {
            totalSum += buffer[i];
        }
    }
    file.close();
    return totalSum;
}
int main() {
    std::string filename = "my_file.txt"; 
    unsigned long long result = sumFileCharacters(filename);
    std::cout << "The total sum of characters in the file is: " << result << std::endl;
    return 0;
}
