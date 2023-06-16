#include "ScavTrap.hpp"
#include "FragTrap.hpp"
int main( void ) 
{
	FragTrap f("fraggie");
	f.attack("scavie");
    f.takeDamage(2);
	f.beRepaired(2);
	f.highFivesGuys();
}