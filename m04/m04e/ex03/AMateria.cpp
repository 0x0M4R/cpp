#include "AMateria.hpp"
AMateria::AMateria(std::string const &type)
{
    std::cout << "AMateria default constructor called !"<<std::endl;
    this->type=type;
}
AMateria::AMateria(AMateria const & copy)
{
    std::cout << "AMateria copy constructor called !"<<std::endl;
    *this=copy;
}
AMateria::~AMateria()
{
    std::cout << "AMateria deconstructor called !"<<std::endl;
}
std::string const &AMateria::getType() const
{
    return this->type;
}
AMateria *AMateria::clone() const 
{
}
