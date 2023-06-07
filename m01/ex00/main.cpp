#include "Zombie.hpp"

int main(void)
{
    Zombie *omar = newZombie("Omar");
    omar->announce();
    randomChump("zomar");
    delete omar;
}