#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
int main()
{
	std::cout << "Constructor and Deconstructor test:\n" << std::endl;
	Animal *arr[2]; 
	for (int i = 0; i < 2; i++)
	{
		if(i < 1)
			arr[i] = new Cat();
		else
			arr[i] = new Dog();
	}
	for (int i = 0; i < 2; i++)
		delete arr[i];
	std::cout << "\nDeep copy test:\n" << std::endl;
	Dog copy;
	{
		Dog deep = copy;
		std::cout << std::endl;
		std::cout << "copied dog idea before deletion: " << deep.getBrain()->getIdea(1) << std::endl;
	}
	std::cout << "copied dog idea after deletion: " << copy.getBrain()->getIdea(1) << std::endl;
}