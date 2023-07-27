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
		Bureaucrat( Bureaucrat const & copy );
		~Bureaucrat();
		Bureaucrat& operator=( Bureaucrat const &copy );
        Bureaucrat& operator<<( Bureaucrat const &copy );
        const std::string getName( void );
        int getGrade( void );
        void incrmentGrade( void ); //reverse 
        void decrementGrade( void ); //reverse
};
std::ostream& operator<<( std::ostream& os, Bureaucrat const &rhs );
#endif
