#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
int main()
{
	Bureaucrat A("omar",145);
	std::cout << "\nShrubbery :\n" << std::endl;
	{
		ShrubberyCreationForm a("home");
		A.executeForm(a);
		A.signForm(a);
		A.executeForm(a);
		A.setGrade(137);
		A.executeForm(a);
	}
	std::cout << "\nRobotomy :\n" << std::endl;
	{
		RobotomyRequestForm a("home");
		A.executeForm(a);
		A.setGrade(72);
		A.signForm(a);
		A.executeForm(a);
		A.setGrade(45);
		A.executeForm(a);
	}
	std::cout << "\nPresidential :\n" << std::endl;
	{
		PresidentialPardonForm a("home");
		A.executeForm(a);
		A.setGrade(25);
		A.signForm(a);
		A.executeForm(a);
		A.setGrade(5);
		A.executeForm(a);
	}
	return (0);
}