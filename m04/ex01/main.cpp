#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
int main()
{
    //create and fill array of animal objects half dogs half cats
    //const Animal* j = new Dog();
    const Animal* i = new Cat();
    //delete j;
    delete i;
    
    //make sure copies are deep copies()
    /*
    std::cout << "Animal Class:" << std::endl;
    const Animal* meta = new Animal();
    std::cout << meta->getType() << std::endl;
    meta->makeSound();
    delete meta;
    std::cout << std::endl;

    std::cout << "Dog Class:" << std::endl;
    const Animal* doug = new Dog();
    std::cout << doug->getType() << std::endl;
    doug->makeSound();
    delete doug;
    std::cout << std::endl;

    std::cout << "WrongCat Class:" << std::endl;
    const Animal* mila = new Cat();
    std::cout << mila->getType() << std::endl;
    mila->makeSound();
    delete mila;
    std::cout << std::endl;
    
    std::cout << "Cat Class:" << std::endl;
    const WrongAnimal* wcat = new WrongCat();
    std::cout << wcat->getType() << std::endl;
    wcat->makeSound();
    delete wcat;
    */
}