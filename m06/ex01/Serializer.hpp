#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>
#include "Data.hpp"
class Serializer
{
	private:
		Data *data;
	public:
		Serializer();
		Serializer( Serializer const & copy );
		~Serializer();
		Serializer& operator=( Serializer const &copy );
		uintptr_t serialize( Data* ptr ) ;
        Data* deserialize( uintptr_t raw ) ;
};

std::ostream& operator<<( std::ostream& os, Data &rhs );
#endif
