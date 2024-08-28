/*The declaration of the function:*/

void func(char = '*', int = 45);

/*is not valid in standard C++ syntax because it incorrectly declares default arguments for the function. Because,
1. Parameter Default Arguments: In C++, each parameter with a default argument must be named in the function declaration. In the code, there are no names for the parameters; only the default values are provided. Each parameter must have a valid identifier.
2. Syntax: The correct way to declare a function with default arguments is to specify both the type, the name, and the default value.

What Happens if Declared Incorrectly?
If we declare the function with the original syntax, the compiler will generate an error indicating that the declaration is invalid. Depending on the compiler, the error message will likely point out that there are unnamed parameters or that the syntax is incorrect. This will generate an error message "type name is not allowed"*/









    


