#include "Bureaucrat.hpp"
int main()
{
    Bureaucrat A("omar", 0);
    std::cout << "A : "<< A << std::endl;
    Bureaucrat B;
    std::cout<<"B : "<< B << std::endl;
    B = A;
    std::cout<<"B : "<< B << std::endl;
    B.setGrade(151);
    std::cout<<"B : "<< B << std::endl;
    // B.decrementGrade();
    // std::cout<<"B : "<< B << std::endl;
    // B.incrmentGrade();
    // std::cout<<"B : "<< B << std::endl;
    // Bureaucrat C(B);
    // std::cout<< "C : "<< C << std::endl;
}