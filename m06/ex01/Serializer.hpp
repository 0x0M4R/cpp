#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>

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
        int getData( Data* ptr ) ;
		uintptr_t serialize( Data* ptr ) ;
        Data* deserialize( uintptr_t raw ) ;
};

typedef struct Data
{
    int data1;
    int data2;
    int data3;
};
std::ostream& operator<<( std::ostream& os, Serializer const &rhs );
#endif
