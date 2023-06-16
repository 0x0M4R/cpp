#include "Cat.hpp"
Cat::Cat()
{
    std::cout << "Cat default constructor called !"<<std::endl;
    this->type="Cat";
}
Cat::Cat(Cat const & copy)
{
    std::cout << "Cat copy constructor called !"<<std::endl;
    *this=copy;
}
Cat::~Cat()
{
    std::cout << "Cat deconstructor called !"<<std::endl;
}
void Cat::makeSound() const { std::cout << "Meowing like a cat! meew!"<<std::endl;}
