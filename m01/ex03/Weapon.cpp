#include "Weapon.hpp"

Weapon::Weapon(void) {
	this->type = type;
	return ;
}

Weapon::~Weapon( void ) {
	return ;
}

void Weapon::setType( std::string type ) {
	this->type = type;
}

const std::string& Weapon::getType ( void ) {
	return (this->type);
}