#ifndef Form_HPP
#define Form_HPP
#include "Bureaucrat.hpp"
#include <iostream>
class Form
{
	private:
		const std::string name;
        bool is_signed;
        const int sign_grade;
        const int exec_grade;
	public:
		Form();
        Form( std::string name, int sign_grade, int exec_grade);
		Form( Form const & copy );
		~Form();
		Form& operator=( Form const &copy );
        std::string getName( void ) const;
        int getSigned( void ) const;
        int getSignGrade( void ) const;
        int getExecGrade( void ) const;
        void beSigned( Bureaucrat B ); //reverse 
        // class GradeTooHighException : public std::exception
		// {
		// 	virtual const char* what(void) const throw();
		// };
		// class GradeTooLowException : public std::exception
		// {
		// 	virtual const char* what(void) const throw();
		// };
};
std::ostream& operator<<( std::ostream& os, Form const &rhs );
#endif
