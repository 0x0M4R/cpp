#include "AForm.hpp"
AForm::AForm():name("default"),is_signed(false), sign_grade(100),exec_grade(50)
{
	std::cout << "AForm default constructor called !" << std::endl;
}

AForm::AForm(std::string name, int sign_grade, int exec_grade):name(name), sign_grade(checkGrade(sign_grade)),exec_grade(checkGrade(exec_grade))
{
    is_signed = false;
	std::cout << "AForm name and grade constructor called !" << std::endl;
}

AForm::AForm(AForm const & copy):name(copy.name),sign_grade(copy.sign_grade),exec_grade(copy.exec_grade)
{
    is_signed = copy.is_signed;
	std::cout << "AForm copy constructor called !" << std::endl;
}

AForm::~AForm() 
{
	std::cout << "AForm deconstructor called !" << std::endl;
}

AForm &AForm::operator=( AForm const &copy )
{
	std::cout << "AForm assignment overload called" << std::endl;
    this->is_signed = copy.is_signed;
    const_cast<std::string&>(this->name) = copy.name;
    const_cast<int&>(this->exec_grade) = copy.exec_grade;
    const_cast<int&>(this->sign_grade) = copy.sign_grade;
	return ( *this );
}

std::string AForm::getName(void) const 
{
	return ( this->name );
}

bool AForm::getSigned(void) const
{
	return ( this->is_signed );
}

int AForm::getExecGrade(void) const
{
	return ( this->exec_grade );
}

int AForm::getSignGrade(void) const
{
	return ( this->sign_grade );
}

void AForm::beSigned(Bureaucrat &B) 
{
    try
    {
        if( B.getGrade() > this->sign_grade)
            throw AForm::GradeTooLowException();
        this->is_signed = true;
        // std::cout << this->getName() << " got signed." << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " can not sign form."<< std::endl;
    }
}

int AForm::checkGrade(int grade) 
{
    try
    {
        if( grade < 1)
            throw AForm::GradeTooHighException();
        else if( grade > 150)
            throw AForm::GradeTooLowException();
    }
    catch(const AForm::GradeTooLowException::exception& e)
    {
        std::cerr << e.what() << " grade will be set to 150." << std::endl;
    }
    catch(const AForm::GradeTooHighException::exception& e)
    {
        std::cerr << e.what() << " grade will be set to 1." << std::endl;
    }
    if( grade < 1)
        return 1;
    else if( grade > 150)
        return 150;
    else
        return grade;
}

bool AForm::execute(Bureaucrat const &executor) const
{
    bool status = true;
    try
    {
        if (getSigned() == false)
        	throw AForm::NotSignedException();
    }
    catch(const AForm::NotSignedException::exception& e)
    {
        std::cerr << e.what() << " can not execute form." << std::endl;
        status = false;
    }
    try
    {
        if (executor.getGrade() > this->getExecGrade())
            throw Bureaucrat::GradeTooLowException();
        this->applyExecution();
    }
    catch(const Bureaucrat::GradeTooLowException::exception& e)
    {
        std::cerr << e.what() << " can not execute form." << std::endl;
        status = false;
    }
    return status;
}

std::ostream& operator<<(std::ostream& os, AForm const &rhs)
{
  return ( os<< "AForm name : "<<rhs.getName() <<", is signed : " <<rhs.getSigned() <<", sign grade : : " <<rhs.getSignGrade() << ", exec grade : " <<rhs.getExecGrade());
}
const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return ("exception : grade is too high.");
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return ("exception : grade is too low...");
}
const char*	AForm::NotSignedException::what(void) const throw()
{
	return ("exception : form not signed.");
}