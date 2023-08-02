#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;
class Form
{
	private:
		const std::string name;
        bool is_signed;
        const int sign_grade;
        const int exec_grade;
		void setExec( int grade ); 
		void setSign( int grade );
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
        void beSigned( Bureaucrat &B ); //reverse
		int checkGrade( int grade );
};
std::ostream& operator<<( std::ostream& os, Form const &rhs );
#endif
