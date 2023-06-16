#include "Brain.hpp"
Brain::Brain()
{
    std::cout << "Brain default constructor called !"<<std::endl;
}
Brain::Brain(Brain const & copy)
{
    std::cout << "Brain copy constructor called !"<<std::endl;
    *this=copy;
}
Brain::~Brain()
{
    std::cout << "Brain deconstructor called !"<<std::endl;
}
Brain &Brain::operator=( Brain const &copy )
{
	std::cout << "Brain assignment overload called" << std::endl;
	this->ideas= = copy.ideas;
	return (*this);
}
