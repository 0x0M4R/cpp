#ifndef AFORM_HPP
#define AFORM_HPP
#include "Bureaucrat.hpp"
// #include "RobotomyRequestForm.hpp"
#include <iostream>

class Bureaucrat;
class AForm
{
	private:
		const std::string name;
        bool is_signed;
        const int sign_grade;
        const int exec_grade;
		void setExec( int grade );
		void setSign( int grade );
	public:
		AForm();
        AForm( std::string name, int sign_grade, int exec_grade);
		AForm( AForm const &copy );
		virtual ~AForm();
		AForm& operator=( AForm const &copy );
        std::string getName( void ) const;
        bool getSigned( void ) const;
        int getSignGrade( void ) const;
        int getExecGrade( void ) const;
        void beSigned( Bureaucrat &B);
		int checkGrade( int grade );
		bool execute( Bureaucrat const &executor) const;
		virtual void applyExecution( void ) const = 0;
        class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what( void ) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what( void ) const throw();
		};
		class NotSignedException : public std::exception
		{
			virtual const char* what( void ) const throw();
		};
};
std::ostream& operator<<( std::ostream& os, AForm const &rhs );
#endif
