#include "WrongAnimal.hpp"
WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called !" << std::endl;
	type = "WrongAnimal";
}

WrongAnimal::WrongAnimal( WrongAnimal const & copy )
{
	std::cout << "WrongAnimal copy constructor called !" << std::endl;
	type = copy.type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal deconstructor called !" << std::endl;
}

WrongAnimal &WrongAnimal::operator=( WrongAnimal const &copy )
{
	std::cout << "WrongAnimal assignment overload called" << std::endl;
	type = copy.type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound !" << std::endl;
}

std::string WrongAnimal::getType() const 
{
	return ( type );
}