#include "Form.hpp"
Form::Form():name("default"),is_signed(false), sign_grade(100),exec_grade(50)
{
	std::cout << "Form default constructor called !" << std::endl;
}

Form::Form(std::string name, int sign_grade, int exec_grade):name(name), sign_grade(checkGrade(sign_grade)),exec_grade(checkGrade(exec_grade))
{
    is_signed = false;
	std::cout << "Form name and grade constructor called !" << std::endl;
}

Form::Form(Form const & copy):name(copy.name),sign_grade(copy.sign_grade),exec_grade(copy.exec_grade)
{
    is_signed = copy.is_signed;
	std::cout << "Form copy constructor called !" << std::endl;
}

Form::~Form() 
{
	std::cout << "Form deconstructor called !" << std::endl;
}

Form &Form::operator=( Form const &copy )
{
	std::cout << "Form assignment overload called" << std::endl;
    this->is_signed = copy.is_signed;
    const_cast<std::string&>(this->name) = copy.name;
    const_cast<int&>(this->exec_grade) = copy.exec_grade;
    const_cast<int&>(this->sign_grade) = copy.sign_grade;
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

void Form::beSigned(Bureaucrat &B) 
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

int Form::checkGrade(int grade) 
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
        return 1;
    else if( grade > 150)
        return 150;
    else
        return grade;
}

std::ostream& operator<<(std::ostream& os, Form const &rhs)
{
  return ( os<< "Form name : "<<rhs.getName() <<", is signed : " <<rhs.getSigned() <<", sign grade : : " <<rhs.getSignGrade() << ", exec grade : " <<rhs.getExecGrade());
}
// const char*	Form::GradeTooHighException::what(void) const throw()
// {
// 	return ("Grade is too high...");
// }

// const char*	Form::GradeTooLowException::what(void) const throw()
// {
// 	return ("Grade is too low...");
// }