#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"
class Cure : public AMateria
{
	public:
		Cure();
        Cure(std::string const & type);
		Cure( Cure const & copy );
		~Cure();
        Cure& operator=( Cure const &copy );
        std::string const & getType() const;
		AMateria* clone() const;
        void use(ICharacter& target);
};
#endif