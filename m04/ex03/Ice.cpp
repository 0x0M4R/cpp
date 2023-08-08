#include "Ice.hpp"
Ice::Ice(): type("ice")
{
	std::cout << "Ice default constructor called !" << std::endl;
}
//While assigning a Materia to another, copying the type doesn’t make sense.
Ice::Ice(Ice const & copy)
{
	std::cout << "Ice copy constructor called !" << std::endl;
}

Ice::~Ice() 
{
	std::cout << "Ice deconstructor called !" << std::endl;
}

Ice &Ice::operator=( Ice const &copy )
{
	std::cout << "Ice assignment overload called" << std::endl;
	return ( *this );
}
std::string const & Ice::getType() const
{
    return (type);
}
AMateria* Ice::clone() const
{
    return (new Ice());
}
void Ice::use( ICharacter& target )
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;

}
