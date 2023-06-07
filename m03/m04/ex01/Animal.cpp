#include "Animal.hpp"
Animal::Animal()
{
    std::cout << "Animal default constructor called !"<<std::endl;
    this->type="Animal";
}
Animal::Animal(Animal const & copy)
{
    std::cout << "Animal copy constructor called !"<<std::endl;
    *this=copy;
}
Animal::~Animal()
{
    std::cout << "Animal deconstructor called !"<<std::endl;
}
void Animal::makeSound() const
{
    std::cout << "Animal sound !"<<std::endl;
}
std::string Animal::getType() const 
{
    return this->type;
}