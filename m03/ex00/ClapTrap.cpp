#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->name = "default";
	hitpoints = 10;
	energypoints = 10;
	attackdamage = 0;
}
ClapTrap::ClapTrap( std::string name )
{
	this->name = name;
	hitpoints = 10;
	energypoints = 10;
	attackdamage = 0;
	std::cout << "ClapTrap: Constructor called for " << this->name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: Deconstructor called for " << name << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & copy )
{
	std::cout << "ClapTrap: copy Constructor called" << std::endl;
	*this = copy;
}
ClapTrap &ClapTrap::operator=( ClapTrap const &copy )
{
	std::cout << "ClapTrap: assignment overload called" << std::endl;
	name = copy.name;
	hitpoints = copy.hitpoints;
	energypoints = copy.energypoints;
	attackdamage = copy.attackdamage;
	return ( *this );
}

void ClapTrap::attack( std::string const &target )
{
	if (energypoints < 1 )
	{
		std::cout << "Claptrap: " << name << " not enough energypoints to attack " << std::endl;
		return;
	}
	energypoints -= 1;
	std::cout << "ClapTrap: " << name << " attacks " << target << ", causing " << attackdamage << " points of damage! energypoints left: " << energypoints << std::endl;
}

void ClapTrap::takeDamage( unsigned int amount )
{
	if ( hitpoints == 0 )
	{
		std::cout << "Claptrap: " << name << " cannot take damage since has he no more health!" << std::endl;
		return ;
	}
	( hitpoints < amount ) ? hitpoints = 0 : hitpoints -= amount;
	std::cout << "ClapTrap: " << name << " took damage causing " << amount<< " points of damage! hitpoints left: " << hitpoints  << std::endl;
}

void ClapTrap::beRepaired( unsigned int amount )
{
	if ( energypoints < 1 )
	{
		std::cout << "Claptrap: " << name << " not enough energypoints to repair " << std::endl;
		return;
	}
	hitpoints += amount;
	energypoints -= 1;
	std::cout << "ClapTrap: " << name << " is being repaired adding " << amount  << " health points!" << std::endl;
}
