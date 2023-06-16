#include "ScavTrap.hpp"

int main( void )
{
	ScavTrap g("miley");
	g.attack("joe");
	g.takeDamage(2);
	g.beRepaired(2);
	g.guardGate();
}