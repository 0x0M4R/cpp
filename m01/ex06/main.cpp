#include "Harl.hpp"

int main( int argc, char **argv )
{
	if ( argc != 2 )
	{
		std::cout << "Error: wrong number of parameters" << std::endl;
		return ( -1 );
	}
	std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	for ( int i = 0; i < 4; i++ )
	{
		if( argv[1] == levels[i] )
			break;
		if( i == 3 )
		{
			std::cout << "Error: level not recognized" << std::endl;
			return ( -1 );
		}
	}
	Harl harl;
	harl.complain( argv[1] );
	return ( 0 );
}