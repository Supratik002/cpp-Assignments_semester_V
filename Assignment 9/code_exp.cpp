#include <iostream>
#include <fstream>
#include <bitset>
void printBitSequenceFromFile(std::string filename)
{
    std::fstream fhand(filename, fhand.binary | fhand.in);
    // One char is exactly one byte
    char c;
    while (fhand.read(reinterpret_cast<char*>(&c), sizeof(c)))
    {
        if (!fhand.eof())
        {
            std::cout << std::bitset<8>(c) << " ";
        }
    }
    std::cout << std::endl;
    fhand.close();
}
int main()
{
    std::string filename = "data.bin";
    signed int a = -10000;
    unsigned short b = 100;
    const char c[] = "WE";
    const size_t str_size = sizeof(c);
    std::cout << "Encoding values:" << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::fstream fhand;
    // trunc will clear the file
    fhand.open(filename, fhand.binary | fhand.trunc | fhand.out);
    fhand.write(reinterpret_cast<char*>(&a), sizeof(a));
    fhand.write(reinterpret_cast<char*>(&b), sizeof(b));
    fhand.write(c, str_size);
    fhand.close();
    std::cout << "Bit sequence in the file: " << std::endl;
    printBitSequenceFromFile(filename);
    signed int d;
    unsigned short e;
    char f[str_size];
    fhand.open(filename, fhand.binary | fhand.in);
    fhand.read(reinterpret_cast<char*>(&d), sizeof(d));
    fhand.read(reinterpret_cast<char*>(&e), sizeof(e));
    fhand.read(f, str_size);
    std::cout << "Decoded values:" << std::endl;
    std::cout << d << std::endl;
    std::cout << e << std::endl;
    std::cout << f << std::endl;
    fhand.close();
}

/*
  The code performs binary file I/O by writing and reading integer and character data. It does the following:

  Encoding Phase:
  ----------------
  Initializes signed int a = -10000, unsigned short b = 100, and const char c[] = "WE".
  Opens a file (data.bin) in binary write mode and writes a, b, and c in binary format using fhand.write().
  Closes the file.
    
  Print Bit Sequence:
  -------------------
  printBitSequenceFromFile() reads each byte of data.bin and displays its 8-bit binary representation using std::bitset<8>(c).
  
  Decoding Phase:
  ---------------
  Reopens data.bin in binary read mode and reads data into variables d, e, and f.
  Outputs d, e, and f to confirm they match the original values.
  Purpose: Demonstrates how to write, read, and verify raw binary data with std::fstream.

*/
