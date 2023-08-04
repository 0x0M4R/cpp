#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5),target("default")
{
	std::cout << "PresidentialPardonForm default constructor called !" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5),target(target)
{
	std::cout << "PresidentialPardonForm target constructor called !" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & copy): AForm(copy)
{
	std::cout << "PresidentialPardonForm copy constructor called !" << std::endl;
	*this=copy;
}

PresidentialPardonForm::~PresidentialPardonForm() 
{
	std::cout << "PresidentialPardonForm deconstructor called !" << std::endl;
}

std::string PresidentialPardonForm::getTarget(void) const
{
	return ( this->target );
}

void PresidentialPardonForm::applyExecution( void ) const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( PresidentialPardonForm const &copy )
{
	if (this != &copy)
		this->target = copy.getTarget();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, PresidentialPardonForm const &rhs)
{
  return ( os<< "PresidentialPardonForm : " << rhs.getTarget());
}