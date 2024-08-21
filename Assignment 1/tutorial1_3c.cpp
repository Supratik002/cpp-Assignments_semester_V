#include <iostream>
int main(){
	float x,y;
	std::cout<<"enter y="<<"\n";
	std::cin>>y;
	x=y-20*6/9;
	std::cout<<"x="<<x<<"\n";
	x=y-20*6./9;
	std::cout<<"x="<<x<<"\n";
	}

/*After Evaluating the following expression in my program:"x=y-20 *6/9", by taking some value of y and 
  printing  the  value  of  x,I didn't see the  expected  result. 
The floating point value of x (the correct result) didn't appear. 
Only integer part of the answer appeared in the terminal.

Therefore, I brought about minimum change(s) at the 8th line to modify my program to make it print the correct result.*/
