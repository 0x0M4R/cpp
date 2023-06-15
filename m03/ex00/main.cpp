#include "ClapTrap.hpp"

int main( void ) 
{
    ClapTrap ct("billy");
    ClapTrap h("joe");
    for (int i = 0; i < 11; i++)
    {
        ct.attack("joe");
        ct.takeDamage(1);
    }
    ct.beRepaired(2);
}