#include"Zombie.hpp"

Zombie::Zombie( void ) 
{
	std::cout << this->name << " alive" << std::endl;
}

Zombie::~Zombie( void ) 
{

	std::cout << this->name << " died" << std::endl;
}

void Zombie::setName(std::string name) 
{
    this->name=name;
}

void	Zombie::announce( void ) {

	std::cout << this->name <<  " BraiiiiiiinnnzzzZ..." << std::endl;
}