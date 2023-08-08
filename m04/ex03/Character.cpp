#include "Character.hpp"
Character::Character(): name("default")
{
	std::cout << "Character default constructor called !" << std::endl;
    for(int i = 0; i < 4 ;i++)
        inventory[i] = NULL;
}

Character::Character(const std::string name):name(name)
{
    for(int i = 0; i < 4 ;i++)
        inventory[i] = NULL;
	std::cout << "Character name constructor called !" << std::endl;
}
//any copy(using copy constructor or copy assignment operator) of a Character must be deep.
Character::Character(Character const & copy) : name(copy.name)
{
    for(int i = 0; i < 4 ;i++)
    {
        if(inventory[i])
            delete inventory[i];
        if ( copy.inventory[i] )
            this->inventory[i] = copy.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
	std::cout << "Character deep copy constructor called !" << std::endl;
}

Character::~Character() 
{
    for(int i = 0; i < 4 ;i++)
     {
        if(inventory[i])
            delete inventory[i];
    }
	std::cout << "Character deconstructor called !" << std::endl;
}

Character &Character::operator=( Character const &copy )
{
    std::cout << "Character assignment overload called" << std::endl;
    if ( this != &copy )
    {
        this->~Character();
        for(int i = 0; i < 4 ;i++)
        {
            if(copy.inventory[i])
                inventory[i] = copy.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
	return ( *this );
}

std::string const & Character::getName() const
{
    return ( name );
}
void Character::use( int idx, ICharacter& target )
{
    if(idx < 4 && idx >=0 && inventory[idx])
        inventory[idx]->use(target);
}
void Character::unequip( int idx )
{
    if (idx < 4 && idx >=0 )
        inventory[idx] = NULL;
}
void Character::equip( AMateria* m)
{
    if(m)
    {
        for(int i = 0; i < 4 ;i++)
        {
            if(!inventory[i])
            {
                inventory[i] = m;
                break ;
            }
        }
    }
}