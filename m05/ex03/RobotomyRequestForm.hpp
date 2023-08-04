#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		~RobotomyRequestForm();
		RobotomyRequestForm&	operator=(RobotomyRequestForm const &copy);
        std::string	getTarget(void) const;
		void applyExecution( void ) const;
	private:
		std::string	target;
};
std::ostream&	operator<<(std::ostream& os, RobotomyRequestForm const &rhs);
#endif