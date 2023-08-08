#include "Cure.hpp"
Cure::Cure(): AMateria("cure")
{
	std::cout << "Cure default constructor called !" << std::endl;
}
Cure::Cure(std::string const & type) : AMateria(type)
{
	std::cout << "Cure copy constructor called !" << std::endl;
}
//While assigning a Materia to another, copying the type doesn’t make sense.
Cure::Cure(Cure const & copy) : AMateria("cure")
{
    (void)copy;
	std::cout << "Cure copy constructor called !" << std::endl;
}

Cure::~Cure() 
{
	std::cout << "Cure deconstructor called !" << std::endl;
}

Cure &Cure::operator=( Cure const &copy )
{
    (void)copy;
    std::cout << "Cure assignment overload called" << std::endl;
	return (*this);
}
std::string const & Cure::getType() const
{
    return (type);
}
AMateria* Cure::clone() const
{
    return (new Cure());
}
void Cure::use( ICharacter& target )
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}