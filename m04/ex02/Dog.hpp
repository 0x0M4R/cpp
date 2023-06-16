#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal
{
	private:
		Brain *dogbrain;
	public:
		Dog();
		Dog(Dog const & copy);
		~Dog();
		Dog& operator=( Dog const &copy );
		void makeSound() const;
		Brain *getBrain( ) const;
};
#endif
