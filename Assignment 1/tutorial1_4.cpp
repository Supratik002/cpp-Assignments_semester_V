#include<iostream>
int main()
{
	int n,i;
	std::cout<<"enter number \n";
	std::cin>>n;
	unsigned int m=1 <<(sizeof(int)*8-1);
	std::cout<<"binary is\n";
	for(i=0; i<sizeof(int)*8; i++)
	{
		if(n&m)
		{
			std::cout<<"1";
		}
		else
		{
			std::cout<<"0";
		}
		m >>=1;
	}
}

