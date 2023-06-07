#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap: default Constructor called" << std::endl;

    this->hitpoints=100;
    this->energypoints=100;
    this->attackdamage=30;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap: deConstructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    std::cout << "FragTrap: name Constructor called" << std::endl;
    this->name=name;
    this->hitpoints=100;
    this->energypoints=100;
    this->attackdamage=30;
}

FragTrap::FragTrap(FragTrap const & copy)
{
    std::cout << "FragTrap: copy Constructor called" << std::endl;
    *this = copy;
}
void FragTrap::attack(std::string const &target)
{
    std::cout << "FragTrap: " << this->name << " attack " << target << ", causing " << this->attackdamage << " points of damage!" << std::endl;
}
void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap: " << this->name <<" requesting high five !" << std::endl;
}