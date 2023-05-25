#include "Zombie.hpp"
void randomChump( std::string name )
{
    Zombie a;
    a.setName(name);
    a.announce();
}