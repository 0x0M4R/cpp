#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>
class WrongAnimal 
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal( WrongAnimal const & copy );
		~WrongAnimal();
		WrongAnimal& operator=( WrongAnimal const &copy );
		void makeSound() const;
		std::string getType() const; 
};
#endif