#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : weapon(weapon) {
	this->name = name;
	return ;
}

HumanA::~HumanA( void ) {
	return ;
}

void	HumanA::attack( void ) {
	std::cout << this->name << " attacks with their "
		<< this->weapon.getType() << std::endl;
}