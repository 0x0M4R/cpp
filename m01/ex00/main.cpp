#include"Zombie.hpp"

int main()
{
	Zombie*  z = newZombie( "omar" );
	z->announce();
	randomChump( "who" );
	z->announce();
	delete z;
}