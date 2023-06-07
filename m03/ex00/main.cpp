#include "ClapTrap.hpp"

int main( void ) {
    ClapTrap ct("billy");
    ClapTrap h("joe");
    ct.attack("joe");
    ct.takeDamage(2);
    ct.beRepaired(2);
}