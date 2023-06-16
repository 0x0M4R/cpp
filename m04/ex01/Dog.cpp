#include "Dog.hpp"
Dog::Dog()
{
    std::cout << "Dog default constructor called !"<<std::endl;
    this->type="Dog";
}
Dog::Dog(Dog const & copy)
{
    std::cout << "Dog copy constructor called !"<<std::endl;
    *this=copy;
}
Dog::~Dog()
{
    std::cout << "Dog deconstructor called !"<<std::endl;
}
Dog &Dog::operator=( Dog const &copy )
{
	std::cout << "Dog assignment overload called" << std::endl;
	type = copy.type;
	return (*this);
}
void Dog::makeSound() const { std::cout << "Rooof like a Dog! woofh!\n";}
