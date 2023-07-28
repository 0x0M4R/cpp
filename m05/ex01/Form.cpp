#include "Form.hpp"
Form::Form():name("default"),is_signed(false), sign_grade(100),exec_grade(50)
{
	std::cout << "Form default constructor called !" << std::endl;
}

Form::Form(std::string name, int sign_grade, int exec_grade):name(name), sign_grade(sign_grade),exec_grade(exec_grade)
{
    is_signed = false;
	std::cout << "Form name and grade constructor called !" << std::endl;
}

Form::Form(Form const & copy):sign_grade(copy.sign_grade),exec_grade(copy.exec_grade)
{
    //check grade here?
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
    this->is_signed = copy.is_signed;
	return ( *this );
}

std::string Form::getName(void) const 
{
	return ( this->name );
}

int Form::getSigned(void) const
{
	return ( this->is_signed );
}

int Form::getExecGrade(void) const
{
	return ( this->exec_grade );
}

int Form::getSignGrade(void) const
{
	return ( this->sign_grade );
}

void Form::beSigned(Bureaucrat B) 
{
    try
    {
        if( B.getGrade() > this->sign_grade)
            throw Bureaucrat::GradeTooLowException();
        this->is_signed = true;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

// const char*	Form::GradeTooHighException::what(void) const throw()
// {
// 	return ("Grade is too high...");
// }

// const char*	Form::GradeTooLowException::what(void) const throw()
// {
// 	return ("Grade is too low...");
// }