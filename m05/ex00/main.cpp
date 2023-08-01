#include "Bureaucrat.hpp"
int main()
{
    Bureaucrat A("omar", 0);
    std::cout << "A : "<< A << std::endl;
    Bureaucrat B;
    B = A;
    std::cout<<"B : "<< B << std::endl;
    B.setGrade(151);
    B.decrementGrade();
    B.incrmentGrade();
    std::cout<< "B : "<< B << std::endl;
    Bureaucrat C(B);
    std::cout<< "C : "<< C << std::endl;
}