#include <iostream>
int main()
{
    std::string s= "HI THIS IS BRAIN";
    std::string *stringPTR = &s;
    std::string &stringREF = s;
    std::cout << "address of string : " << &s << std::endl;
    std::cout << "address using stringPTR : " << stringPTR << std::endl;
    std::cout << "address using stringREF : " << &stringREF << std::endl;
    std::cout << "string using stringPTR : " << *stringPTR << std::endl;
	std::cout << "string using stringREF : " << stringREF << std::endl;
    return 0;
}