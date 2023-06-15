#include "ScavTrap.hpp"
#include "FragTrap.hpp"
int main( void ) {
    ClapTrap ct("clappy");
    ClapTrap h("joe");
    ct.attack("joe");
    ct.takeDamage(2);
    ct.beRepaired(2);
    ScavTrap g("scaviee");
    g.attack("joe");
    g.guardGate();
    FragTrap f("fraggie");
    f.attack("scavie");
    f.highFivesGuys();
}