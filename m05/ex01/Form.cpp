#include "Form.hpp"
Form::Form():name("default"),grade(150)
{
	std::cout << "Form default constructor called !" << std::endl;
}

Form::Form(std::string name, int grade):name(name)
{
	std::cout << "Form name and grade constructor called !" << std::endl;
    this->setGrade(grade);
}

Form::Form(Form const & copy)
{
	std::cout << "Form copy constructor called !" << std::endl;
    *this = copy;
}

Form::~Form() 
{
	std::cout << "Form deconstructor called !" << std::endl;
}

Form &Form::operator=( Form const &copy )
{
	std::cout << "Form assignment overload called" << std::endl;
    this->grade = copy.grade ;
	return ( *this );
}

std::string Form::getName(void) const 
{
	return ( this->name );
}

int Form::getGrade(void) const
{
	return ( this->grade );
}

void Form::beSigned(Bureaucrat B) 
{
    try
    {
        if( grade < 1)
            throw Form::GradeTooHighException();
        if( grade > 150)
            throw Form::GradeTooLowException();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
	this->grade = grade;
}

// const char*	Form::GradeTooHighException::what(void) const throw()
// {
// 	return ("Grade is too high...");
// }

// const char*	Form::GradeTooLowException::what(void) const throw()
// {
// 	return ("Grade is too low...");
// }