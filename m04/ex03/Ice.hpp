#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"
class Ice : public AMateria
{
	private:
		const std::string type;
	public:
		Ice();
		Ice( Ice const & copy );
		~Ice();
        Ice& operator=( Ice const &copy );
        std::string const & getType() const;
		AMateria* clone() const;
        void use(ICharacter& target);
};
#endif