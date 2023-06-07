#include <iostream>
#include <string>
#include <fstream>

void	replace(std::string filename, std::string s1, std::string s2)
{
	std::ifstream input_file(filename);
	if (!input_file) {
		std::cerr << "Error: file cannot be opened" << std::endl;
		exit(-1);
	}
	if (input_file.good()) {
		if (input_file.peek() == std::ifstream::traits_type::eof())
				std::cout << "Error: file is empty" << std::endl;
		else {
			std::ofstream output_file(filename.append(".replace").data());
			while (input_file.good() && output_file.good()) {
				std::string line;
				std::size_t word;
				std::getline(input_file, line);
				word = line.find(s1, 0);
				while (word != std::string::npos)
				{
					line.erase(word, s1.length());
					line.insert(word, s2);
					word = line.find(s1, word);
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
		std::cout << "Error: " << strerror(errno) << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc == 4)
		replace(argv[1], argv[2], argv[3]);
	else {
		std::cerr << "Error: ./replace <filename> <string1> <string2>" << std::endl;
		exit(-1);
	}
	return 0;
}