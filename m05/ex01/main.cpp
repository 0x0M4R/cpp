#include "Bureaucrat.hpp"
int main()
{
    Bureaucrat A("omar", 0);
    A.getGrade();
    std::cout<<A.getName() << std::endl;
    Bureaucrat B;
    B = A;
    std::cout<<B.getName() << std::endl;
    B.setGrade(151);
    A.setGrade(0);
}