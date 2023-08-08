#include "Ice.hpp"
Ice::Ice() : AMateria("ice")
{
}
//While assigning a Materia to another, copying the type doesn’t make sense.
Ice::Ice(Ice const & copy) : AMateria(copy.type)
{
    (void)copy;
}

Ice::~Ice() 
{
}

Ice &Ice::operator=( Ice const &copy )
{
    (void)copy;
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
