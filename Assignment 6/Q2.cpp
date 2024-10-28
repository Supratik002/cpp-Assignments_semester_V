/*
Explain the output of the program? Find the error.
struct foo{
  foo(){cout << "foo()\n" ;}
  ~foo(){cout <<"~foo()\n";}
  int i {5};
};
struct obj{
  const foo& getFoo(){return my_foo;};
  foo my_foo;
};
int main()
{
  obj *o = new obj();
  const foo& val = o->getFoo();
  cout << "val.i=" << val.i << std::endl;
  delete o;
  cout << "val.i=" << val.i << std::endl;
}
*/

/*
Program Output:
---------------
The expected output, until the undefined behavior occurs, is:

foo() // from constructing `my_foo` in `obj`
val.i=5 // accessing `val.i`
~foo() // from destructing `my_foo` when `o` is deleted
val.i=??? // undefined behavior (could print garbage or crash)
*/

/*
Error:
-----
The error is in the use of `val.i` after `o` is deleted. Since `val` is a reference to a member of `o`, deleting `o` makes `val` a dangling reference, leading to undefined behavior when accessed.
*/

