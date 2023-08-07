#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include<random>
Base *generate(void)
{
    srand((unsigned int)time(NULL));
    int num = std::rand() % 3;
    if (num == 1)
        return new A();
    else if (num == 2)
        return new B();
    else
        return new C();
    
}
void identify(Base* p)
{
    if ((A*)dynamic_cast<A*>(p) != nullptr){
		std::cout << "A" << std::endl;
	}
	if ((B*)dynamic_cast<B*>(p) != nullptr){
		std::cout << "B" << std::endl;
	}
	if ((C*)dynamic_cast<C*>(p) != nullptr){
		std::cout << "C" << std::endl;
	}
}
void identify(Base& p)
{
    try
    {
		Base ptr = dynamic_cast<A&>(p);
		(void)ptr;
		std::cout << "A" << std::endl;
	}
    catch (std::bad_cast){}
	try 
    {
		Base ptr = dynamic_cast<B&>(p);
		(void)ptr;
		std::cout << "B" << std::endl;
	}catch (std::bad_cast){}
	try{
		Base ptr = dynamic_cast<C&>(p);
		(void)ptr;
		std::cout << "C" << std::endl;
	}catch (std::bad_cast){}
}
int main()
{
    Base* bp = generate();

	identify( bp );
	identify( *bp );

	delete bp;

	return 0;
}
