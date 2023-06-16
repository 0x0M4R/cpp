#include "WrongCat.hpp"
WrongCat::WrongCat()
{
    std::cout << "WrongCat default constructor called !"<<std::endl;
    this->type="WrongCat";
}
WrongCat::WrongCat(WrongCat const & copy)
{
    std::cout << "WrongCat copy constructor called !"<<std::endl;
    *this=copy;
}
WrongCat::~WrongCat()
{
    std::cout << "WrongCat deconstructor called !"<<std::endl;
}

WrongCat &WrongCat::operator=( WrongCat const &copy )
{
	std::cout << "WrongCat assignment overload called" << std::endl;
	type = copy.type;
	return (*this);
}

