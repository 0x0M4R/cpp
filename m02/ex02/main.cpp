#include "Fixed.hpp"

int main( void ) {
Fixed a(25.5f);
Fixed b( 10 );
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
return 0;
}