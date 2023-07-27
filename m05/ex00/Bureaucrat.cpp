#include "Bureaucrat.hpp"
Bureaucrat::Bureaucrat():name("default"),grade(150)
{
	std::cout << "Bureaucrat default constructor called !" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade):name(name),grade(grade)
{
	std::cout << "Bureaucrat name and grade constructor called !" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy)
{
	std::cout << "Bureaucrat copy constructor called !" << std::endl;
    *this = copy;
}

Bureaucrat::~Bureaucrat() 
{
	std::cout << "Bureaucrat deconstructor called !" << std::endl;
}

Bureaucrat &Bureaucrat::operator=( Bureaucrat const &copy ) 
{
	std::cout << "Bureaucrat assignment overload called" << std::endl;
    name = copy.name;
    grade = copy.grade;
	return ( *this );
}

std::string Bureaucrat::getName(void) const 
{
	return ( this->name );
}

int Bureaucrat::getGrade(void) const
{
	return ( this->grade );
}

void Bureaucrat::incrmentGrade(void)
{
    this->grade--;
	return;
}

void Bureaucrat::decrementGrade(void)
{
    this->grade++;
	return;
}


std::ostream& operator<<(std::ostream& os, Bureaucrat const &rhs)
{
  return ( os<<rhs.getName() <<", bureacrat grade " <<rhs.getGrade());
}