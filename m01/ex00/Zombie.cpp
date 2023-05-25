#include "Zombie.hpp"
void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..."<<std::endl;
}
std::string Zombie::getName()
{
    return this->name;
}
void Zombie::setName(std::string name)
{
    this->name = name;
}
