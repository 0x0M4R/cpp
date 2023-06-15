#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), FragTrap(), ScavTrap()
{
    std::cout << "DiamondTrap: default Constructor called" << std::endl;
    FragTrap::hitpoints = 100;
    ScavTrap::energypoints = 50;
    FragTrap::attackdamage = 30;
}

DiamondTrap::~DiamondTrap() 
{
    std::cout << "DiamondTrap: Deconstructor called for " << name << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap( name ), FragTrap( name ), ScavTrap( name )
{
    std::cout << "DiamondTrap: Constructor called for " << name << std::endl;
    this->name = name;
    ClapTrap::name = name;
    FragTrap::hitpoints = 100;
    ScavTrap::energypoints = 50;
    FragTrap::attackdamage = 30;
}

DiamondTrap &DiamondTrap::operator=( DiamondTrap const &copy )
{
	std::cout << "FragTrap: assignment overload called" << std::endl;
	name = copy.name;
	hitpoints = copy.hitpoints;
	energypoints = copy.energypoints;
	attackdamage = copy.attackdamage;
	return ( *this );
}

DiamondTrap::DiamondTrap( DiamondTrap const & copy )
{
    std::cout << "DiamondTrap: copy Constructor called for " << name << std::endl;
    *this = copy;
}
void DiamondTrap::attack( std::string const &target )
{
    ScavTrap::attack( target );
}
void	DiamondTrap::whoAmI( void ) {

	std::cout << "DiamondTrap: I am " << this->name << ", ClapTrap name is " << ClapTrap::name <<std::endl;
}