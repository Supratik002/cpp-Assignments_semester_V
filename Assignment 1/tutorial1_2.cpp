#include<iostream>
int main()
{
	double x,y;
	std::cout<<"enter number\n";
	std::cin>>x;
	if(x==0.0)
	{
		std::cout<<"change x";
	}
	else
	{
		y=x+1/(x+(1/(x+1/x)));
		std::cout<<"the ans is "<< y <<"\n";
	}
}
