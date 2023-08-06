#include "Conversion.hpp"
int main(int ac,char **av)
{
	try
	{
		if (ac == 2)
			Conversion a(av[1]);
	}
	catch(...)
	{
		std::cout << "invalid input"<<std::endl;
	}
	return(0);
}
//  double a =12.;
