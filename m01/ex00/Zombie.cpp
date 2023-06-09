#include"Zombie.hpp"

Zombie::Zombie( void ) 
{
}

Zombie::~Zombie( void ) 
{
	std::cout << this->name << " destroyed" << std::endl;
}

void Zombie::setName(std::string name) 
{
	this->name=name;
}

void	Zombie::announce( void ) 
{
	if ( !(this->name.empty()) )
		std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	else
		std::cout << "Error: announce: the zombie has not been initialized" << std::endl;
}