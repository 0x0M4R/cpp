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

Bureaucrat::Bureaucrat(Bureaucrat const & copy):name(copy.name),grade(copy.grade)
{
	std::cout << "Bureaucrat copy constructor called !" << std::endl;
    // *this = copy;
}

Bureaucrat::~Bureaucrat() 
{
	std::cout << "Bureaucrat deconstructor called !" << std::endl;
}

Bureaucrat &Bureaucrat::operator=( Bureaucrat const &copy )
{
	std::cout << "Bureaucrat assignment overload called" << std::endl;
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
        if( grade > 150)
            throw Bureaucrat::GradeTooLowException();
    }
    catch(const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << " grade will be set to 1." <<std::endl;
        this->grade = 1;
        return;
    }
    catch(const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << " grade will be set to 150." << std::endl;
        this->grade = 150;
        return;
    }
    this->grade = grade;
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("exception : bureaucrat's grade too high.");
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("exception : bureaucrat's grade too low.");
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