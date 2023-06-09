#include"Zombie.hpp"

int main()
{
	Zombie*  z = newZombie( "omar" );
	z->announce();

	randomChump( "who" );

	Zombie x("zomar");
	x.announce();
	delete z;
}