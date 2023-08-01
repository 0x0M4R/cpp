#include "Form.hpp"
int main()
{
    Form a("form",151,0);
    std::cout << a << std::endl;
    Form b(a);
    std::cout << b << std::endl;
    Form c;
    c = a;
    std::cout << c << std::endl;
    Bureaucrat A;
    std::cout << A << std::endl;
    c.beSigned(A);
    std::cout << c << std::endl;
    A.signForm(c);
}