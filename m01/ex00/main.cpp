#include"Zombie.hpp"

int main() {
	
	Zombie*  z = newZombie( "omar" );
	z->announce();
	randomChump( "who" );

	delete z;
}