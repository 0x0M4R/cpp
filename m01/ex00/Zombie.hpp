//add debugging message in desconstuctor
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie( std::string );
		~Zombie();
		void announce( void );
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );
#endif