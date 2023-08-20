#include "RPN.hpp"

RPN::RPN(){}
RPN::~RPN(){}
RPN::RPN(RPN const &copy)
{
    *this=copy;
}
RPN& RPN::operator=( RPN const &copy ) 
{
    if ( this != &copy )
        this->v = copy.v;
    return *this;
}
RPN::RPN(char *input)
{
    for(int i=0; input[i]!='\0';i++)
    {
        if(isdigit(input[i]))
        {
            v.push_back(input[i] - '0');
            if (input[i + 1] && isdigit(input[i+ 1]))
            {
                std::cout << "Error : Invalid input." << std::endl;
                return;
            }
        }
        else if(input[i] == '+' && v.size() > 1)
        {
           int a = v.back();
            v.pop_back();
            int b = v.back();
            v.pop_back();
            v.push_back(a + b);
            std::cout << input[i] << " = " << v.back() << '\n';
        }
        else if(input[i] == '-' && v.size() > 1)
        {
            int a = v.back();
            v.pop_back();
            int b = v.back();
            v.pop_back();
            v.push_back(b - a);
            std::cout << input[i] << " = " << v.back() << '\n';
        }
        else if(input[i] == '*' && v.size() > 1)
        {
            int a = v.back();
            v.pop_back();
            int b = v.back();
            v.pop_back();
            v.push_back(a * b);
            std::cout << input[i] << " = " << v.back() << '\n';
        }
        else if(input[i] == '/' && v.size() > 1)
        {
            int a = v.back();
            v.pop_back();
            int b = v.back();
            v.pop_back();
            v.push_back(b / a);
            std::cout << input[i] << " = " << v.back() << '\n';
        }
        else if(input[i] == ' ')
            continue;
        else
        {
            std::cout << "Error : Invalid input." << std::endl;
            return;
        }
    }
    if (v.size() == 1)
	{
		int result = v.front();
		v.pop_back();
		std::cout << "Result: " << result << std::endl;
	}
	else
	{
		std::cout << "Error : Invalid input." << std::endl;
	}
}
