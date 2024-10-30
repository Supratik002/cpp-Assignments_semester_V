/*
  I didn't get this idea of the program by my brain. What I got through browsing is the following:
  To handle memory for shallow copies and ensure it’s released when there are no remaining shallow copies in scope, we need a reference-counting mechanism. This way, when the last shallow copy goes out of scope, the memory can be safely deallocated.
  
  My code is based on this idea. Now I don't know if it's correct or not. It runs on my machine. 
*/

#include <iostream>
#include <cstring> // for std::memcpy

class myvector {
  int *p;                // base pointer of the vector
  unsigned int size;     // size of the vector
  unsigned int* ref_count; // reference count for shallow copies
  bool shallow;          // flag indicating if this is a shallow copy

public:
  // Default constructor: create an empty vector
  myvector() : p(nullptr), size(0), ref_count(new unsigned int(1)), shallow(false) {}

  // Constructor to create a vector of length 'n' initialized to 0
  myvector(unsigned int n) : size(n), ref_count(new unsigned int(1)), shallow(false) {
    p = new int[size](); // initialize all elements to 0
  }

  // Copy constructor: can be shallow or deep depending on the 'shallow' flag
  myvector(const myvector& v, bool shallow = true) : p(v.p), size(v.size), ref_count(v.ref_count), shallow(shallow) {
    if (shallow) {
      // For shallow copy, increase the reference count
      (*ref_count)++;
    } else {
      // For deep copy, allocate new memory and copy data
      p = new int[size];
      ref_count = new unsigned int(1);
      std::memcpy(p, v.p, size * sizeof(int));
    }
  }

  // Destructor
  ~myvector() {
    // Decrement the reference count if this is a shallow copy
    if (shallow) {
      (*ref_count)--;
    }
    // Free the memory when no more references exist
    if (*ref_count == 0) {
      delete[] p;
      delete ref_count;
    }
  }

  // Return the base pointer to the vector
  int* get_ptr() const {
    return p;
  }

  // Return the size of the vector
  constexpr unsigned int get_size() const {
    return size;
  }

  // Return the shallow flag
  bool is_shallow() const {
    return shallow;
  }

  // Update the element at index 'i' with 'val'
  void update(unsigned int i, int val) {
    if (i < size) {
      p[i] = val;
    } else {
      std::cerr << "Index out of bounds.\n";
    }
  }

  // Return the element at index 'i'
  constexpr int get(unsigned int i) const {
    return i < size ? p[i] : 0; // returns 0 if index is out of bounds
  }

  // Print the vector contents to the console
  void print() const {
    for (unsigned int i = 0; i < size; ++i) {
      std::cout << p[i] << " ";
    }
    std::cout << std::endl;
  }

  // Expand the vector and insert a new value at the end
  void push_back(int val) {
    int* new_p = new int[size + 1];
    std::memcpy(new_p, p, size * sizeof(int));
    new_p[size] = val;

    if (*ref_count == 1) {
      delete[] p;
      delete ref_count;
    } else {
      (*ref_count)--;
    }

    p = new_p;
    ref_count = new unsigned int(1);
    shallow = false;
    ++size;
  }
};

int main() {
  myvector x(7); // create a vector of size 7 initialized to 0
  for (unsigned int i = 0; i < 7; i++)
    x.update(i, 10 + 5 * i);

  myvector v{x}; // shallow copy
  v.update(1, 100);
  v.print();
  // print the contents of x and verify that x has also changed on updating v.
  x.print();

  myvector y{x, false}; // deep copy
  y.update(1, 200);
  y.print();
  // print the contents of x and verify that x has NOT changed on updating y.
  x.print();

  // push_back 500 on y and verify
  y.push_back(500);
  y.print();

  return 0;
}
