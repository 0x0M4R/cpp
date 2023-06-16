#include "DiamondTrap.hpp"

int main( void )
{
	DiamondTrap d("diamondie");
	d.attack("sam");
    d.beRepaired(10);
    d.takeDamage(10);
	d.highFivesGuys();
	d.guardGate();
	d.whoAmI();
}