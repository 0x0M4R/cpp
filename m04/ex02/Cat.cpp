#include "Cat.hpp"
Cat::Cat()
{
	std::cout << "Cat default constructor called !" << std::endl;
	this->type = "Cat";
	this->catbrain = new Brain();
}

Cat::Cat(Cat const & copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called !" << std::endl;
	type = copy.type;
	catbrain = new Brain ( *copy.catbrain );
}

Cat::~Cat() 
{
	std::cout << "Cat deconstructor called !" << std::endl;
	delete catbrain;

}

Cat &Cat::operator=( Cat const &copy )
{
	std::cout << "Cat assignment overload called" << std::endl;
	if (this != &copy)
	{
		if (this->catbrain)
			delete this->catbrain;
		type = copy.type;
		catbrain = new Brain ( *copy.catbrain );
	}
	return ( *this );
}

void Cat::makeSound() const 
{
	std::cout << "Meowing like a cat! meew!" << std::endl;
}
