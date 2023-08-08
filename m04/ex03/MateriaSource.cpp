#include "MateriaSource.hpp"
MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called !" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & copy)
{
	std::cout << "MateriaSource copy constructor called !" << std::endl;
}

MateriaSource::~MateriaSource() 
{
	std::cout << "MateriaSource deconstructor called !" << std::endl;
}

MateriaSource &MateriaSource::operator=( MateriaSource const &copy )
{
	std::cout << "MateriaSource assignment overload called" << std::endl;
	return ( *this );
}
void MateriaSource::learnMateria(AMateria* m)
{
    if(count != 4)
    {
        inventory[count] = m;
        count++;
    }
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
    if (type == "ice")
        return new Ice();
    if (type == "cure")
        return new Cure();
    return 0;
}
