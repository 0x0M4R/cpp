#ifndef CONVERSION_HPP
#define CONVERSION_HPP
#include <iostream>
#include <sstream>
#include <limits.h>
#include <cmath>
class Conversion
{
	private:
		std::string input;
        char type;
        int i;
        float f;
        double d;
        char c;
	public:
		Conversion();
		Conversion(std::string input);
		Conversion( Conversion const & copy );
		~Conversion();
		Conversion& operator=( Conversion const &copy );
		void convert( void ) ;
        void display( void ) ;
};
std::ostream& operator<<( std::ostream& os, Conversion const &rhs );
#endif
