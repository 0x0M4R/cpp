#include "Serializer.hpp"

Serializer::Serializer()
{

}

Serializer::Serializer(int data1, int data2, int data3)
{
    data->data1 = data1;
    data->data2 = data2;
    data->data3 = data3;
}

Serializer::~Serializer()
{

}
// Serializer::Serializer( Serializer const & copy )
// {

// }

// Serializer &Serializer::operator=( Serializer const &copy )
// {

// }

std::ostream& operator<<(std::ostream& os, Serializer const &rhs)
{
	return ( os<< "data1: " <<rhs->d );
}

int Serializer::getData( Data* ptr )
{
    
}
uintptr_t Serializer::serialize( Data* ptr )
{

}
Data* Serializer::deserialize( uintptr_t raw )
{
    
}
