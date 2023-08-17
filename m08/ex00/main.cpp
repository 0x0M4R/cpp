#include "easyfind.hpp"
#include <algorithm>

int main( int ac, char ** av )
{
    if ( ac != 2 )
    {
        std::cout << "Wrong number of parameters!" << std::endl;
        return 1;
    }
    
    int temp;
    std::istringstream o(av[1]);
    o >> temp;
    if ( !o.eof() || o.fail())
	{
        std::cout << "Invalid integer!" << std::endl;
        return 1;
    }
    int                 arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::vector< int >      vect( arr, arr + sizeof( arr ) / sizeof( int ) );
    std::list< int >        list( arr, arr + sizeof( arr ) / sizeof( int ) );

    easyfind( vect, temp);
    easyfind( list,temp);

    return 0;
}