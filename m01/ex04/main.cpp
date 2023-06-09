#include <iostream>
#include <string>
#include <fstream>

int	replace( std::string filename, std::string s1, std::string s2 )
{
	std::ifstream input_file( filename );
	if ( !input_file )
	{
		std::cerr << "Error: file doesnt exist / cannot be opened" << std::endl;
		return( -1 );
	}
	if ( input_file.good() )
	{
		if ( input_file.peek() == EOF )
		{
				std::cout << "Error: file is empty" << std::endl;
				return ( -1 );
		}
		else
		{
			std::ofstream output_file( filename + ".replace" );
			while ( input_file.good() && output_file.good() )
			{
				std::string line;
				std::getline( input_file, line );
				std::size_t word = line.find( s1, 0 );
				while ( word != std::string::npos )
				{
					line.erase( word, s1.length() );
					line.insert( word, s2 );
					word = line.find( s1, word );
				}
				output_file << line;
				if (input_file.eof())
					break;
				output_file << std::endl;
			}
			input_file.close();
			output_file.close();
		}
	}
	else
		std::cout << "Error: " << strerror( errno ) << std::endl;
	return ( 0 );
}

int	main( int argc, char **argv )
{
	if ( argc == 4 )
		return ( replace( argv[1], argv[2], argv[3] ) );
	else
	{
		std::cerr << "Error: wrong parameters \nUsage: ./sed <filename> <s1> <s2>" << std::endl;
		return( -1 );
	}
}