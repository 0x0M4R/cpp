#include "Bureaucrat.hpp"
Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat default constructor called !" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy)
{
	std::cout << "Bureaucrat copy constructor called !" << std::endl;
}

Bureaucrat::~Bureaucrat() 
{
	std::cout << "Bureaucrat deconstructor called !" << std::endl;
}

Bureaucrat &Bureaucrat::operator=( Bureaucrat const &copy )
{
	std::cout << "Bureaucrat assignment overload called" << std::endl;
}

const std::string Bureaucrat::getName(void)
{
	return ( this->name );
}

int Bureaucrat::getGrade(void)
{
	return ( this->grade );
}

void Bureaucrat::incrmentGrade(void)
{
	return;
}

void Bureaucrat::decrementGrade(void)
{
	return;
}


std::ostream& operator<<(std::ostream& os, Bureaucrat const &rhs)
{
  return ( os<<rhs );
}