#ifndef HUMAN_B
# define HUMAN_B
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string		name;
		Weapon*			weapon;

	public:
		HumanB( std::string name );
		~HumanB( void );
		void	setWeapon( Weapon& weapon );
		void	attack( void );
};
#endif