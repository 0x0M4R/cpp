#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137),target("default")
{
	std::cout << "ShrubberyCreationForm default constructor called !" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137),target(target)
{
	std::cout << "ShrubberyCreationForm target constructor called !" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy): AForm(copy)
{
	std::cout << "ShrubberyCreationForm copy constructor called !" << std::endl;
	*this=copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{
	std::cout << "ShrubberyCreationForm deconstructor called !" << std::endl;
}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return ( this->target );
}

void ShrubberyCreationForm::applyExecution( void) const
{
	std::ofstream	f;
	f.open((this->target + "_shrubbery").c_str());
	f << "                    ,@@@@@@@,"<< std::endl;
	f << "    ,,,.   ,@@@@@@/@@,  .oo8888o."<< std::endl;
	f << "    ,&%%&%&&%,@@@@@/@@@@@@,8888/88/8o"<< std::endl;
	f << ",%&/%&&%&&%,@@@/@@@/@@@88/88888/88'"<< std::endl;
	f << "%&&%&%&/%&&%@@/@@/ /@@@88888/88888'"<< std::endl;
	f << "%&&%/ %&%%&&@@/ V /@@' `88/8 `/88'"<< std::endl;
	f << "`&%/ ` /%&'    |.|        / '|8'"<< std::endl;
	f << "    |o|        | |         | |"<< std::endl;
	f << "    |.|        | |         | |"<< std::endl;
	f << "    /// ._///_/__/  ,/_//__///.  /_//__/_"<< std::endl;
	f.close();
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( ShrubberyCreationForm const &copy )
{
	if (this != &copy)
		this->target = copy.getTarget();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, ShrubberyCreationForm const &rhs)
{
	return ( os<< "ShrubberyCreationForm : " << rhs.getTarget());
}