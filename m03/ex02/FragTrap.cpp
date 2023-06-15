#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap: default Constructor called" << std::endl;
	name = "default";
	hitpoints = 100;
	energypoints = 100;
	attackdamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: Deconstructor called for " << name << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name )
{
	std::cout << "FragTrap: name Constructor called for " << name << std::endl;
	this->name = name;
	this->hitpoints = 100;
	this->energypoints = 100;
	this->attackdamage = 30;
}

FragTrap::FragTrap( std::string *name ) : ClapTrap ( name )
{
	if( name == NULL)
	{
		std::cout << "FragTrap: Error name is NULL " << std::endl;
		exit(1);
	}
	this->name = *name;
	hitpoints = 10;
	energypoints = 10;
	attackdamage = 0;
	std::cout << "FragTrap: Constructor called for " << this->name << std::endl;
}

FragTrap::FragTrap( FragTrap const & copy )
{
	std::cout << "FragTrap: copy Constructor called" << std::endl;
	*this = copy;
}

FragTrap &FragTrap::operator=( FragTrap const &copy )
{
	std::cout << "FragTrap: assignment overload called" << std::endl;
	name = copy.name;
	hitpoints = copy.hitpoints;
	energypoints = copy.energypoints;
	attackdamage = copy.attackdamage;
	return ( *this );
}

void FragTrap::attack( std::string const &target )
{
	if ( energypoints < 1 )
	{
		std::cout << "Fragtrap: " << name << " not enough energypoints to attack " << std::endl;
		return;
	}
	energypoints -= 1;
	std::cout << "FragTrap: " << name << " attacks " << target << ", causing " << attackdamage << " points of damage! energypoints left: " << energypoints << std::endl;
}

void FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap: " << this->name <<" requesting high five !" << std::endl;
}