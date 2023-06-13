#include "Fixed.hpp"

int main( void ) 
{
	Fixed a( 25.5f );
	Fixed b( 0 );
	std::cout << "a+b : "<< a+b << std::endl;
	std::cout << "a/b : "<< a/b << std::endl;
	std::cout << "a*b : " << a*b << std::endl;
	std::cout <<  "a-b : "<<a-b << std::endl;
	std::cout <<  "a>b : ";
	(a>b)? std::cout<< "true" <<std::endl  : std::cout<< "false"<<std::endl;
	std::cout <<  "a<b : ";
	(a<b)? std::cout<< "true" <<std::endl  : std::cout<< "false"<<std::endl;
	std::cout <<  "a>=b : ";
	(a>=b)? std::cout<< "true" <<std::endl  : std::cout<< "false"<<std::endl;
	std::cout <<  "a<=b : ";
	(a<=b)? std::cout<< "true" <<std::endl  : std::cout<< "false"<<std::endl;
	std::cout <<  "a==b : ";
	(a==b)? std::cout<< "true" <<std::endl  : std::cout<< "false"<<std::endl;
	std::cout <<  "a!=b : ";
	(a!=b)? std::cout<< "true" <<std::endl  : std::cout<< "false"<<std::endl;
	std::cout <<  "++a :"<< ++a << std::endl;
	std::cout <<  "a++ : "<<a++ << std::endl;
	std::cout <<  "a : "<<a << std::endl;
	std::cout <<  "--a :"<< --a << std::endl;
	std::cout <<  "a-- : "<<a-- << std::endl;
	std::cout <<  "a : "<<a << std::endl;
	std::cout <<  "max : "<< Fixed::max(a,b)<< std::endl;
	std::cout <<  "min : "<< Fixed::min(a,b)<< std::endl;
	const Fixed a_c(25.5f);
	const Fixed b_c( 10 );
	std::cout <<  "max const : "<< Fixed::max(a_c,b_c)<< std::endl;
	std::cout <<  "min const: "<<  Fixed::min(a_c,b_c)<< std::endl;
	return 0;
}