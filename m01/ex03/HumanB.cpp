#include "HumanB.hpp"

HumanB::HumanB( std::string name ) {
	this->name = name;
	this->weapon = NULL;
	return ;
}

HumanB::~HumanB( void ) {
	return ;
}

void	HumanB::setWeapon( Weapon& weapon ) {
	this->weapon = &weapon;
}

void	HumanB::attack( void ) {
	std::string		weaponType;

	this->weapon ? weaponType = weapon->getType() : weaponType = "hands";
	std::cout << this->name << " attacks with their "
		<< weaponType << std::endl;
}