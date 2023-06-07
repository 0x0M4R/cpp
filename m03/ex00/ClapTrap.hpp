#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
class ClapTrap
{
private:
    std::string name;
    unsigned int hitpoints;
    unsigned int energypoints;
    unsigned int attackdamage;

public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(ClapTrap const & copy);
    ~ClapTrap();
    void attack(std::string const &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
#endif