#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap: default Constructor called" << std::endl;

    this->hitpoints=100;
    this->energypoints=50;
    this->attackdamage=10;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap: deConstructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap: name Constructor called" << std::endl;
    this->name=name;
    this->hitpoints=100;
    this->energypoints=50;
    this->attackdamage=10;
}

ScavTrap::ScavTrap(ScavTrap const & copy)
{
    std::cout << "ScavTrap: copy Constructor called" << std::endl;
    *this = copy;
}
void ScavTrap::attack(std::string const &target)
{
    std::cout << "ScavTrap: " << this->name << " attack " << target << ", causing " << this->attackdamage << " points of damage!" << std::endl;
}
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap: " << this->name << " has entered gate keeping mode !" << std::endl;
}