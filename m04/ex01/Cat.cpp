#include "Cat.hpp"
Cat::Cat()
{
	std::cout << "Cat default constructor called !" << std::endl;
	this->type = "Cat";
	this->catbrain = new Brain();
}

Cat::Cat( Cat const & copy ) : Animal( copy )
{
	*this = copy;
}

Cat::~Cat() 
{
	std::cout << "Cat deconstructor called !" << std::endl;
	delete catbrain;
}

Cat &Cat::operator=( Cat const &copy )
{
	std::cout << "Cat assignment overload called" << std::endl;
	type = copy.type;
	catbrain = new Brain ( *copy.catbrain );
	return ( *this );
}

void Cat::makeSound() const 
{
	std::cout << "Meowing like a cat! meew!" << std::endl;
}

Brain* Cat::getBrain() const
{
	return ( catbrain );
}