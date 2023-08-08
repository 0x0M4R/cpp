#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"
class Character : public ICharacter
{
	private:
		const std::string name;
        AMateria *inventory[4];
        int count;
	public:
		Character();
		Character( const std::string name );
        Character( Character const & copy );
		~Character();
        Character& operator=( Character const &copy );
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};
#endif