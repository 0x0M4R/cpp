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
		virtual ~WrongAnimal();
		WrongAnimal& operator=( WrongAnimal const &copy );
		virtual void makeSound() const;
		std::string getType() const; 
};
#endif