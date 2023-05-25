#include "Zombie.hpp"
Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "Zombie " << this->name << " spawns" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " destroyed" << std::endl;
}
void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..."<<std::endl;
}
// std::string Zombie::getName()
// {
//     return this->name;
// }
// void Zombie::setName(std::string name)
// {
//     this->name = name;
// }
