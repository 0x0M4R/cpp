#include "Character.hpp"
Character::Character(): name("default")
{
    for(int i = 0; i < 4 ;i++)
        inventory[i] = NULL;
}

Character::Character(const std::string &name):name(name)
{
    for(int i = 0; i < 4 ;i++)
        inventory[i] = NULL;
}

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
}

Character::~Character() 
{
    for(int i = 0; i < 4 ;i++)
     {
        if(inventory[i])
            delete inventory[i];
    }
}

Character &Character::operator=( Character const &copy )
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