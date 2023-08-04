#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include "Form.hpp"
class Form;
class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat( Bureaucrat const & copy );
		~Bureaucrat();
		Bureaucrat& operator=( Bureaucrat const &copy );
		Bureaucrat& operator<<( Bureaucrat const &copy );
		std::string getName( void ) const;
		int getGrade( void ) const;
		void setGrade( int grade );
		void incrmentGrade( void );
		void decrementGrade( void ); 
		void signForm( Form& form ); 
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};
};
std::ostream& operator<<( std::ostream& os, Bureaucrat const &rhs );
#endif
