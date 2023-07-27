#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
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
        void incrmentGrade( void ); //reverse 
        void decrementGrade( void ); //reverse
};
std::ostream& operator<<( std::ostream& os, Bureaucrat const &rhs );
#endif
