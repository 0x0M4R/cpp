#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"
class Cure : public AMateria
{
	private:
		const std::string type;
	public:
		Cure();
		Cure( Cure const & copy );
		~Cure();
        Cure& operator=( Cure const &copy );
        std::string const & getType() const;
		AMateria* clone() const;
        void use(ICharacter& target);
};
#endif