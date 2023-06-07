#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap: default Constructor called" << std::endl;
    this->hitpoints=10;
    this->energypoints=10;
    this->attackdamage=0;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap: deConstructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap: name Constructor called" << std::endl;
    this->name=name;
    this->hitpoints=10;
    this->energypoints=10;
    this->attackdamage=0;
}

ClapTrap::ClapTrap(ClapTrap const & copy)
{
    std::cout << "ClapTrap: copy Constructor called" << std::endl;
    *this = copy;
}
void ClapTrap::attack(std::string const &target)
{
    std::cout << "ClapTrap: " << this->name << " attack " << target << ", causing " << this->attackdamage << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap: " << this->name << " took damage causing " << amount<< " points of damage!" << std::endl;
    this->hitpoints-=amount;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "ClapTrap: " << this->name << " is being repaired adding " << amount<< " health points!" << std::endl;
    this->hitpoints+=amount;
}
