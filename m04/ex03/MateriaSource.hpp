#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"
class MateriaSource : public IMateriaSource
{
    private:
        AMateria *inventory[4];
        int count;
	public:
		MateriaSource();
        MateriaSource( MateriaSource const & copy );
		~MateriaSource();
        MateriaSource& operator=( MateriaSource const &copy );
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};
#endif