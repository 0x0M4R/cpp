#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
class DiamondTrap : public FragTrap, public ScavTrap
{
private:
    std::string name;
public:
    DiamondTrap();
    DiamondTrap( std::string name );
    DiamondTrap( std::string* name );
    DiamondTrap( DiamondTrap const & copy );
    ~DiamondTrap();
	DiamondTrap& operator=( DiamondTrap const &copy );
    void attack( std::string const &target );
    void	whoAmI( void );
};
#endif