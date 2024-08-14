#include <iostream>
int main(){
	float x,y;
	std::cout<<"x=\n";
	std::cin>>x;
	y=x+(1/(x+(1/(x+1/x))));
	std::cout<<"y="<<y<<"\n";
	}
