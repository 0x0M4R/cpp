#include "Character.hpp"
Character::Character()
{
	std::cout << "Character default constructor called !" << std::endl;
}

Character::Character(const std::string name):name(name)
{
    count = 0;
	std::cout << "Character name constructor called !" << std::endl;
}
//any copy(using copy constructor or copy assignment operator) of a Character must be deep.
Character::Character(Character const & copy)
{
	std::cout << "Character copy constructor called !" << std::endl;
}

Character::~Character() 
{
	std::cout << "Character deconstructor called !" << std::endl;
}

Character &Character::operator=( Character const &copy )
{
	std::cout << "Character assignment overload called" << std::endl;
	return ( *this );
}

std::string const & Character::getName() const
{
    return ( name );
}
void Character::use( int idx, ICharacter& target )
{
    if(idx < count)
        inventory[idx]->use(target);
}
void Character::unequip( int idx )
{
    for(int i = idx; i < 3; i++)
        inventory[idx] = inventory[idx + 1];
    count--;
}
void Character::equip( AMateria* m)
{
    if(count != 4)
    {
        inventory[count] = m;
        count++;
    }
}