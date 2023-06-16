#include "Animal.hpp"
Animal::Animal()
{
	std::cout << "Animal default constructor called !"<<std::endl;
	type = "Animal";
}

Animal::Animal( Animal const & copy )
{
	std::cout << "Animal copy constructor called !"<<std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "Animal deconstructor called !"<<std::endl;
}

Animal &Animal::operator=( Animal const &copy )
{
	std::cout << "Animal assignment overload called" << std::endl;
	type = copy.type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "Animal sound !"<<std::endl;
}

std::string Animal::getType() const 
{
	return type;
}