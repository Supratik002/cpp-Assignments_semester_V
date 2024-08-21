#include<iostream>
#include<math.h>
int main()
{
	int k,m;
	float n,nn,p;
	std::cout<<"enter the number";
	std::cin>>n;
	std::cout<<"enter the kth place";
	std::cin>>k;
	nn=n*pow(10,k);
	nn=nn+0.5;
	m=(int)nn;
	p=(float)m/pow(10,k);
	std::cout<<"the ans is "<<p<<"\n";
}
