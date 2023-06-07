#include "ScavTrap.hpp"

int main( void ) {
    ClapTrap ct("billy");
    ClapTrap h("joe");
    ct.attack("joe");
    ct.takeDamage(2);
    ct.beRepaired(2);
    ScavTrap g("miley");
    g.attack("robert");
    g.guardGate();
}