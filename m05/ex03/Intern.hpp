#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
class Intern
{
	public:
		Intern();
		Intern(Intern const &copy);
		~Intern();
		Intern&	operator=(Intern const &copy);
		AForm *makeForm(std::string form, std::string target);
		AForm *newPresident(std::string form);
		AForm *newRobotomy(std::string form);
		AForm *newShrubbery(std::string form);
};
std::ostream&	operator<<(std::ostream& os, Intern const &rhs);
#endif