#include <iostream>
int main()
{
	char capVowel1, capCowel2,capVowel3,capVowel4,capVowel5;
	std::cout<<"Enter vowels:\n";
	std::cin>>capVowel1>>capVowel2>>capVowel3>>capVowel4>>capVowel5;
	int x=capVowel5-capVowel1;
	std::cout<<"x="<<x<<"\n";
	}
/*The answer is coming out to be same in both 3a and 3b.
Reason : Though the ASCII values for the small and capital vowels are different. 
          But the difference between two small vowels and the difference between two capital vowels are exactly same.*/
