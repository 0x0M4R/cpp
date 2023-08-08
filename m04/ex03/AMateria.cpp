#include "AMateria.hpp"
AMateria::AMateria() : type("default") //abstract never going to construct
{
}
AMateria::AMateria(std::string const & type) : type(type)
{
}

AMateria::~AMateria()
{
}
AMateria::AMateria(AMateria const & copy) : type(copy.type)
{
}
AMateria &AMateria::operator=( AMateria const &copy )
{
    (void)copy;
    return *this;
}
void AMateria::use(ICharacter& target)
{
	(void)target;
}
std::string const & AMateria::getType() const
{
    return (type);
}