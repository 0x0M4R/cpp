#ifndef Weapon_HPP
# define Weapon_HPP
#include <iostream>
class Weapon
{
    private:
        std::string type;
    public:
        Weapon(std::string);
        ~Weapon(void);
        const std::string& getType(void);
        void setType( std::string );
};
#endif