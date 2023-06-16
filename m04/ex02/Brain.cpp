#include "Brain.hpp"
Brain::Brain()
{
    for(int i = 0; i < 100; i++ )
    {
        std::ostringstream ss;
        ss << i;
        ideas[i] = "idea " + ss.str();
    }
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
    if (this != &copy)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = copy.ideas[i];
    }
	return (*this);
}
std::string &Brain::getIdea( int i ) 
{
    return ( ideas[i] );
}