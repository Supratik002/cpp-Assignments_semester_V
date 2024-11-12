#include <iostream>
#include <fstream>
#include <string>
void copyFile(const std::string& sourceFilename, const std::string& destinationFilename) {
    // Open the source file in text mode
    std::ifstream sourceFile(sourceFilename);
    if (!sourceFile) {
        std::cerr << "Error: Could not open source file " << sourceFilename << std::endl;
        return;
    }
    // Open the destination file in text mode
    std::ofstream destinationFile(destinationFilename);
    if (!destinationFile) {
        std::cerr << "Error: Could not open destination file " << destinationFilename << std::endl;
        return;
    }
    // Copy the file line by line using getline
    std::string line;
    while (std::getline(sourceFile, line)) {
        destinationFile << line << '\n'; // Write each line and add a newline
    }
    std::cout << "File copied successfully from " << sourceFilename << " to " << destinationFilename << std::endl;
    // Close both files
    sourceFile.close();
    destinationFile.close();
}
int main() {
    std::string sourceFilename = "my_file.txt"; // Replace with your source file path
    std::string destinationFilename = "destination.txt"; // Replace with your destination file path
    copyFile(sourceFilename, destinationFilename);
    return 0;
}
