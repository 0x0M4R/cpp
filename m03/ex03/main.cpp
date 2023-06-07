#include "DiamondTrap.hpp"

int main( void ) {
    std::cout<< "ClapTrap test:" << std::endl;
    ClapTrap ct("clappy");
    ct.attack("joe");
    ct.takeDamage(2);
    ct.beRepaired(2);
    std::cout<< "\n";
    std::cout<< "ScavTrap test:" << std::endl;
    ScavTrap g("scaviee");
    g.attack("robert");
    g.guardGate();
    std::cout<< "\n";
    std::cout<< "FragTrap test:" << std::endl;
    FragTrap f("fraggie");
    f.attack("scavie");
    f.highFivesGuys();
    std::cout<< "\n";
    std::cout<< "DiamondTrap test:" << std::endl;
    DiamondTrap d("diamondie");
    d.attack("sam");
    d.highFivesGuys();
    d.guardGate();
    d.whoAmI();
    std::cout<< "\n";
}