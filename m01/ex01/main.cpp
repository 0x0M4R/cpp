#include "Zombie.hpp"

int main(void)
{
    int n = -1;
	Zombie	*zombs = zombieHorde(n, "omar");

	for (int i = 0; i < n; i++) {
		zombs[i].announce();
	}
	delete [] (zombs);
}