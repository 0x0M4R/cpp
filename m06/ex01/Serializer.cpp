#include "Serializer.hpp"

Serializer::Serializer()
{

}

Serializer::~Serializer()
{

}

uintptr_t Serializer::serialize( Data* ptr )
{
    return( reinterpret_cast<uintptr_t>(ptr));
}
Data* Serializer::deserialize( uintptr_t raw )
{
    return( reinterpret_cast<Data *>(raw));
}

std::ostream& operator<<(std::ostream& os, Data &rhs) 
{
	return ( os<< "data1= " <<rhs.data1 << ", data2= "<<rhs.data2 <<", data= " <<rhs.data3 << ", address= " << &rhs);
}