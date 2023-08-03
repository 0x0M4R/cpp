#include "Form.hpp"
int main()
{
    Form a;
    std::cout << "a | " << a << std::endl;
    Form c("form1",151,0);
    std::cout << "c | " << c << std::endl;
    Form b(c);
    std::cout << "b | " << b << std::endl;
    Bureaucrat A;
    std::cout << A << std::endl;
    A.signForm(c);
    std::cout << c << std::endl;
}