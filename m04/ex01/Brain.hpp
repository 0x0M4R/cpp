#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
#include <sstream>
 
class Brain 
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(Brain const & copy);
        ~Brain();
        Brain& operator=( Brain const &copy );
        std::string &getIdea( int i );
};
#endif