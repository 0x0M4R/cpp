#include "Serializer.hpp"

int main()
{
    Data d = {
        429.23,
        -3,
        false
    };
    
    Serializer s;
    std::cout << d << std::endl;
    uintptr_t byte = s.serialize(&d);
    std::cout << "serialized to byte array : "<< byte << std::endl;
    Data *ptr = s.deserialize(byte);
    if (ptr == &d)
        std::cout << "deserialization returns same object!" << std::endl;
    std::cout << *ptr << std::endl;
	return(0);
}
