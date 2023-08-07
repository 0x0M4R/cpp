#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>

struct Data;
class Serializer
{
	private:
		Data *data;
	public:
		Serializer();
        Serializer( int data1, int data2, int data3);
		Serializer( Serializer const & copy );
		~Serializer();
		Serializer& operator=( Serializer const &copy );
        int getData( int index ) ;
		uintptr_t serialize( Data* ptr ) ;
        Data* deserialize( uintptr_t raw ) ;
};

struct Data
{
    int data1;
    int data2;
    int data3;
};
std::ostream& operator<<( std::ostream& os, Serializer &rhs );
#endif
