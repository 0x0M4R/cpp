#include "MateriaSource.hpp"
MateriaSource::MateriaSource()
{
    for(int i = 0; i < 4 ;i++)
        inventory[i] = NULL;
	std::cout << "MateriaSource default constructor called !" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & copy)
{
    for(int i = 0; i < 4 ;i++)
    {
        if (copy.inventory[i])
            inventory[i] = copy.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
	std::cout << "MateriaSource copy constructor called !" << std::endl;
}

MateriaSource::~MateriaSource() 
{
    for(int i = 0; i < 4 ;i++)
    {
        if(inventory[i])
        delete inventory[i];
    }
	std::cout << "MateriaSource deconstructor called !" << std::endl;
}

MateriaSource &MateriaSource::operator=( MateriaSource const &copy )
{
    if ( this != &copy )
    {
        for(int i = 0; i < 4 ;i++)
        {
            if(inventory[i])
                delete inventory[i];
            if(copy.inventory[i])
                inventory[i] = copy.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
	std::cout << "MateriaSource assignment overload called" << std::endl;
	return ( *this );
}
void MateriaSource::learnMateria(AMateria* m)
{
    for(int i=0;i < 4;i++)
    {
        if(!inventory[i])
        {
            inventory[i] = m;
            break ;
        }
    }
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
    for(int i=0;i < 4;i++)
    {
        if(inventory[i] && inventory[i]->getType() == type)
            return (inventory[i]->clone());
    }
    return 0;
}
