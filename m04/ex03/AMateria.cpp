#include "AMateria.hpp"
AMateria::AMateria()
{
    std::cout << "Ice default constructor called !" << std::endl;
}
AMateria::AMateria(std::string const & type) : type(type)
{
    std::cout << "AMateria type constructor called !" << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "AMateria deconstructor called !" << std::endl;
}
AMateria::AMateria(AMateria const & copy)
{
    (void)copy;
    std::cout << "AMateria copy constructor called !" << std::endl;
}
AMateria &AMateria::operator=( AMateria const &copy )
{
    (void)copy;
    std::cout << "AMateria assignment constructor called !" << std::endl;
    return *this;
}
void AMateria::use(ICharacter& target)
{
	(void)target;
}
// std::string const & AMateria::getType() const
// {
//     return (type);
// }