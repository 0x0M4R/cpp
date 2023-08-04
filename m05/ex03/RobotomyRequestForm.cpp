#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45),target("default")
{
	std::cout << "RobotomyRequestForm default constructor called !" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45),target(target)
{
	std::cout << "RobotomyRequestForm target constructor called !" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & copy): AForm(copy)
{
	std::cout << "RobotomyRequestForm copy constructor called !" << std::endl;
	*this=copy;
}

RobotomyRequestForm::~RobotomyRequestForm() 
{
	std::cout << "RobotomyRequestForm deconstructor called !" << std::endl;
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return ( this->target );
}

void RobotomyRequestForm::applyExecution( void ) const
{
	std::cout << "DRILLING NOISES." << std::endl;
		if (std::rand() % 2 == 1)
			std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
		else
			std::cout << this->getTarget() << " robotomy failed." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( RobotomyRequestForm const &copy )
{
	if (this != &copy)
		this->target = copy.getTarget();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, RobotomyRequestForm const &rhs)
{
	return ( os<< "RobotomyRequestForm : " << rhs.getTarget());
}