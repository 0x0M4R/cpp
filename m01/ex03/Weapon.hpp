#ifndef Weapon_HPP
# define Weapon_HPP
#include <iostream>
class Weapon
{
    private:
        std::string type;
    public:
        Weapon(void);
        ~Weapon(void);
        const std::string& getType(void);
        void setType( std::string );
};
#endif