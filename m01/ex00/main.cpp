#include"Zombie.hpp"

int main()
{
	Zombie*  z = newZombie( "omar" );
	z->announce();
	randomChump( "who" );

	// Zombie x;
	// x.announce();
	// x.setName("zomar");
	// x.announce();
	delete z;
}