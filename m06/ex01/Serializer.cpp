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

int Serializer::getData( int index )
{
    if (index == 1)
        return data->data1;
    else if (index == 2)
        return data->data2;
    else if ( index == 3)
        return data->data3;
    return 0;
}

uintptr_t Serializer::serialize( Data* ptr )
{
    (void)ptr;
    return 0;
}
Data* Serializer::deserialize( uintptr_t raw )
{
    (void)raw;
    return NULL;
}

std::ostream& operator<<(std::ostream& os, Serializer &rhs) 
{
	return ( os<< "data1: " <<rhs.getData(1));
}