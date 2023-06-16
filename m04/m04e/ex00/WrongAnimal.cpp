#include "WrongAnimal.hpp"
WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal default constructor called !"<<std::endl;
    this->type="WrongAnimal";
}
WrongAnimal::WrongAnimal(WrongAnimal const & copy)
{
    std::cout << "WrongAnimal copy constructor called !"<<std::endl;
    *this=copy;
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal deconstructor called !"<<std::endl;
}
void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound !"<<std::endl;
}
std::string WrongAnimal::getType() const 
{
    return this->type;
}