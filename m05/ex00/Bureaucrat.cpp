#include "Bureaucrat.hpp"
Bureaucrat::Bureaucrat():name("default"),grade(150)
{
	std::cout << "Bureaucrat default constructor called !" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade):name(name)
{
	std::cout << "Bureaucrat name and grade constructor called !" << std::endl;
    this->setGrade(grade);
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
    const_cast<std::string&>(this->name) = copy.name;
    this->grade = copy.grade ;
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

void Bureaucrat::setGrade(int grade) 
{
    try
    {
        if( grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else if( grade > 150)
            throw Bureaucrat::GradeTooLowException();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    if( grade < 1)
            this->grade = 1;
    else if( grade > 150)
        this->grade = 150;
    else
        this->grade = grade;
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high.");
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low.");
}

void Bureaucrat::incrmentGrade(void)
{
    this->setGrade(this->grade - 1);
	return;
}

void Bureaucrat::decrementGrade(void)
{
    this->setGrade(this->grade + 1);
	return;
}


std::ostream& operator<<(std::ostream& os, Bureaucrat const &rhs)
{
  return ( os<<rhs.getName() <<", bureacrat grade " <<rhs.getGrade());
}