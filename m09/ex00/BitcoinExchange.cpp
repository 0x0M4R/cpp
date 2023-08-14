#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    parse_csv("./data.csv", ',');
}
BitcoinExchange::~BitcoinExchange()
{
}
Date BitcoinExchange::parse_date(std::string date)
{
	Date temp;
	int temp_i;
	size_t pos = date.find('-');
	if (pos == std::string::npos)
	{
			std::cerr << "Error : Invalid date, row #" << std::endl;
	}
	std::istringstream o(date.substr(0, pos));
	// std::cout << o << std::endl;
    if (o >> temp_i && o.eof() && !o.fail())
    {
		;
    }
	else
		std::cout << "invalid date" << std::endl;
	o.clear();
	return temp;
}
std::map <Date,float> BitcoinExchange::parse_csv(const char *file, char delimeter)
{
	std::map <Date,float> temp;
	std::ifstream csv(file);
    // if (!csv.is_open())
	// 	return NULL;
    std::string line;
	std::getline(csv, line); //skip header
	std::cout << line << std::endl;
	int i = 1;
	while(std::getline(csv, line))
	{
		size_t pos = line.find(delimeter);
		if (pos == std::string::npos)
		{
			std::cerr << "Error : Missing delimeter, row #" << i << " in " << file << std::endl;
			continue;
		}
		Date date = parse_date(line.substr(0, pos));
		(void)date;
		i++;
    }
	return temp;
}