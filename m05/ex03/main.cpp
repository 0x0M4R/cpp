#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern i;
	Bureaucrat b("director", 1);

	AForm *pardon = i.makeForm("PresidentialPardon", "manager");
	b.executeForm(*pardon);
	b.signForm(*pardon);
	b.executeForm(*pardon);
	delete pardon;	

	AForm *shrubbery = i.makeForm("ShrubberyCreation", "shrubs");
	b.executeForm(*shrubbery);
	b.signForm(*shrubbery);
	b.executeForm(*shrubbery);
	delete shrubbery;

	AForm *robotomy = i.makeForm("RobotomyRequest", "robot");
	b.executeForm(*robotomy);
	b.signForm(*robotomy);
	b.executeForm(*robotomy);
	delete robotomy;

	AForm *random = i.makeForm("nothing", "nowhere");
    delete random;
	return (0);
}