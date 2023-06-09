#include"Zombie.hpp"

int main() {
	
	Zombie*	horde = zombieHorde( 13, "zmbie" );

	for (int i = 0; i < 13; i++) {

		horde[i].announce();
	}

	delete[] horde;	
}