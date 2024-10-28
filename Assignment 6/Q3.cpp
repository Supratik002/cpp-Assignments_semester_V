/*Explain the output of the following program:
#include<iostream>
using namespace std;
struct X
{
  X(){cout << "default constructor\n";};
  X(X&& x){ cout << "move constructor\n";};
  X(const X&x){cout << "copy constructor\n";};
  X& operator=(const X&){cout << "copy  assignment\n"; return *this;};
  ~X(){cout << "Destructor\n";};
};
X foo(X x){
  return x;
}
int main()
{
  X obj;
  obj = foo(obj);
}
*/

/*
Expected Output:
----------------
The output would likely be:

default constructor // for `obj` in main
copy constructor // for `x` in `foo(obj)`
move constructor // to move `x` to the return value of `foo`
copy assignment // to assign the returned `X` to `obj`
Destructor // for `x` in `foo`, as it goes out of scope
Destructor // for the temporary moved into `obj`
Destructor // for `obj` in main

*/
