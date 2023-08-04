#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called !" << std::endl;
}


Intern::Intern(Intern const & copy)
{
	std::cout << "Intern copy constructor called !" << std::endl;
	*this=copy;
}

Intern::~Intern() 
{
	std::cout << "Intern deconstructor called !" << std::endl;
}

AForm* Intern::newPresident(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::newRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::newShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string form, std::string target)
{
	std::string forms[3] = {
		"PresidentialPardon",
		"RobotomyRequest",
		"ShrubberyCreation"
	};
	AForm	*(Intern::*create_form[3])(std::string target) = {
		&Intern::newPresident,
		&Intern::newRobotomy,
		&Intern::newShrubbery,
	};
	for(int i = 0; i < 3; i++)
	{
		if (form == forms[i])
		{
			AForm *ret = (this->*create_form[i])(target);
			std::cout << "Intern created "<< form << " form." <<std::endl;
			return (ret);
		}
	}
	std::cout << "Form "<< form << " doesnt exist" << std::endl;
	return (NULL);
}


Intern &Intern::operator=( Intern const &copy )
{
	(void) copy;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, Intern const &rhs)
{
	(void)rhs;
	return ( os<< " <Intern object> " );
}