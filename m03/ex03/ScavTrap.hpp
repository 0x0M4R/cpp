#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const & copy );
		~ScavTrap();
		ScavTrap& operator=( ScavTrap const &copy );
		void attack( std::string const &target );
		void guardGate();
};
#endif