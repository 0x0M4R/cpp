#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap: default Constructor called for " << name << std::endl;
	name = "default";
	hitpoints = 100;
	energypoints = 50;
	attackdamage = 20;
}

ScavTrap::~ScavTrap() 
{
	std::cout << "ScavTrap: Deconstructor called for " << name << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name )
{
	std::cout << "ScavTrap:  Constructor called for " << name << std::endl;
	this->name = name;
	hitpoints = 100;
	energypoints = 50;
	attackdamage = 20;
}

ScavTrap::ScavTrap( ScavTrap const &copy )
{
    std::cout << "ScavTrap: copy Constructor called" << std::endl;
	*this = copy;
}

ScavTrap &ScavTrap::operator=( ScavTrap const &copy )
{
    std::cout << "ScavTrap: assignment overload called" << std::endl;
	name = copy.name;
	hitpoints = copy.hitpoints;
	energypoints = copy.energypoints;
	attackdamage = copy.attackdamage;
	return ( *this );
}

void ScavTrap::attack( std::string const &target )
{
	if ( energypoints < 1 )
	{
		std::cout << "Scavtrap: " << name << " not enough energypoints to attack " << std::endl;
		return;
	}
	energypoints -= 1;
	std::cout << "ScavTrap: " << name << " attacks " << target << ", causing " << attackdamage << " points of damage! energypoints left: " << energypoints << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap: " << this->name << " has entered gate keeping mode !" << std::endl;
}