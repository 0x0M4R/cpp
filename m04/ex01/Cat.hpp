#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"
class Cat : public Animal
{
	private:
		Brain *catbrain;
	public:
		Cat();
		Cat(Cat const & copy);
		~Cat();
		Cat& operator=( Cat const &copy );
		void makeSound() const;
		Brain *getBrain( ) const;
};
#endif
