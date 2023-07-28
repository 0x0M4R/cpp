#include "Form.hpp"
int main()
{
    Bureaucrat A("omar", 0);
    std::cout<<A.getName() << std::endl;
    Bureaucrat B;
    B = A;
    std::cout<<B.getName() << std::endl;
    B.setGrade(151);
    A.setGrade(0);
    Form a("form",151,0);
    std::cout << a.getName() << a.getExecGrade() << a.getSignGrade() << a.getSigned() << std::endl;
}