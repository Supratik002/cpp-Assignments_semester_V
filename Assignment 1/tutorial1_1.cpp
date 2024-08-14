#include <iostream>
int main(){
	int p,y,w,d;
	std::cout<<"Enter number of days:\n";
	std::cin>>p;
	y=p/365;
	p=p%365;
	w=p/7;
	d=p%7;
	std::cout<<y<<"years"<<w<<"weeks"<<d<<"days"<<"\n";
	}
