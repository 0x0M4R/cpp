#include "WrongCat.hpp"
WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called !" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat( WrongCat const & copy ) : WrongAnimal(copy)
{
	std::cout << "WrongCat copy constructor called !" << std::endl;
	type = copy.type;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat deconstructor called !" << std::endl;
}

WrongCat &WrongCat::operator=( WrongCat const &copy )
{
	std::cout << "WrongCat assignment overload called" << std::endl;
	type = copy.type;
	return ( *this );
}

void WrongCat::makeSound() const 
{ 
	std::cout << "Meowing like a wrong cat! meew!"<< std::endl;
}

