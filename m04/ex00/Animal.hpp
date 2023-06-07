#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
class Animal 
{
protected:
    std::string type;
public:
    Animal();
    Animal(Animal const & copy);
    virtual ~Animal();
    virtual void makeSound() const;
    std::string getType() const; 
};
#endif