#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm&	operator=(ShrubberyCreationForm const &copy);
        std::string	getTarget(void) const;
		void execute( Bureaucrat const &executor) const;
	private:
		std::string	target;
};
std::ostream&	operator<<(std::ostream& os, ShrubberyCreationForm const &rhs);
#endif