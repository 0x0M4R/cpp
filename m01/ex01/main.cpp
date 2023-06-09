#include"Zombie.hpp"

int main() 
{
	int j = 12;
	Zombie*	horde = zombieHorde( j, "zmbie" );

	for (int i = 0; i < j; i++) 
	{
		horde[i].announce();
	}
	delete[] horde;	
}