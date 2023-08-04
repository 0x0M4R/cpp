#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &copy);
		~PresidentialPardonForm();
		PresidentialPardonForm&	operator=(PresidentialPardonForm const &copy);
        std::string	getTarget(void) const;
		void applyExecution( void ) const;
	private:
		std::string	target;
};
std::ostream&	operator<<(std::ostream& os, PresidentialPardonForm const &rhs);
#endif