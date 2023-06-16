#include "Dog.hpp"
Dog::Dog()
{
	std::cout << "Dog default constructor called !" << std::endl;
	this->type = "Dog";
	this->dogbrain = new Brain();

}

Dog::Dog( Dog const & copy ) : Animal( copy )
{
	std::cout << "Dog copy constructor called !" << std::endl;
	*this = copy;
}

Dog::~Dog()
{
	std::cout << "Dog deconstructor called !" << std::endl;
	delete dogbrain;
}

Dog &Dog::operator=( Dog const &copy )
{
	std::cout << "Dog assignment overload called" << std::endl;
	type = copy.type;
	dogbrain = new Brain (*copy.dogbrain);
	return ( *this );
}
void Dog::makeSound() const 
{ 
	std::cout << "Rooof like a Dog! woofh!" << std::endl;
}
Brain* Dog::getBrain() const
{
	return ( dogbrain );
}