#include "Cure.hpp"
Cure::Cure(): AMateria("cure")
{
}
Cure::Cure(std::string const & type) : AMateria(type)
{
    (void)type;
}

Cure::Cure(Cure const & copy) : AMateria(copy.type)
{
    (void)copy;
}

Cure::~Cure() 
{
}

Cure &Cure::operator=( Cure const &copy )
{
    (void)copy;
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
