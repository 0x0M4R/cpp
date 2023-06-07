#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    std::cout << "DiamondTrap: default Constructor called" << std::endl;

    this->hitpoints=FragTrap::hitpoints;
    this->energypoints=ScavTrap::energypoints;
    this->attackdamage=FragTrap::attackdamage;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap: deConstructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
    std::cout << "DiamondTrap: name Constructor called" << std::endl;
    this->name=name;
    ClapTrap::name=name;
    this->hitpoints=FragTrap::hitpoints;
    this->energypoints=ScavTrap::energypoints;
    this->attackdamage=FragTrap::attackdamage;
}

DiamondTrap::DiamondTrap(DiamondTrap const & copy)
{
    std::cout << "DiamondTrap: copy Constructor called" << std::endl;
    *this = copy;
}
void DiamondTrap::attack(std::string const &target)
{
    ScavTrap::attack(target);
}
void	DiamondTrap::whoAmI( void ) {

	std::cout << "DiamondTrap: I am " << this->name << ", ClapTrap name is " << ClapTrap::name <<std::endl;
}