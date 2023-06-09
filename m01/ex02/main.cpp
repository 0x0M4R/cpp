#include <iostream>

int main()
{
	std::string s= "HI THIS IS BRAIN";
	std::string *stringPTR = &s;
	std::string &stringREF = s;
	std::cout << "memory address of string : " << &s << std::endl;
	std::cout << "memory address of stringPTR : " << stringPTR << std::endl;
	std::cout << "memory address of stringREF : " << &stringREF << std::endl;
	std::cout << "value of string : " << s << std::endl;
	std::cout << "value of stringPTR : " << *stringPTR << std::endl;
	std::cout << "value of stringREF : " << stringREF << std::endl;
	return 0;
}