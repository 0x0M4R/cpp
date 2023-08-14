#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    price = parse_csv("./data.csv", ',');
}
BitcoinExchange::~BitcoinExchange()
{
}
std::string BitcoinExchange::trim_ws(std::string s)
{
	const char* ws = " \t\r";
	s.erase(s.find_last_not_of(ws) + 1);
	s.erase(0, s.find_first_not_of(ws));
	return s;
}
Date BitcoinExchange::parse_date(std::string date)
{
	date = trim_ws(date);
	std::string::difference_type n = std::count(date.begin(), date.end(), '-');
	if (n != 2)
		std::cout << "invalid '-' token detected" << std::endl;
	if (date.length() != 10 )
		std::cout << "invalid date format" << std::endl;
	if (date.find_first_of('-') != 4)
		std::cout << "invalid date format" << std::endl;
	if (date.find_last_of('-') != 7)
		std::cout << "invalid date format" << std::endl;
	Date temp;
	int temp_i = 0;

	std::istringstream o(date.substr(0, 4));
    if (o >> temp_i && o.eof() && !o.fail() && temp_i > 0 && temp_i < 10000)
		temp.year = temp_i;
	else
		std::cout << "invalid year" << std::endl;
	o.str(date.substr(5, 2));
    o.clear();
	if (o >> temp_i && o.eof() && !o.fail() && temp_i > 0 && temp_i < 13)
		temp.month = temp_i;
	else
		std::cout << "invalid month" << std::endl;
	o.str(date.substr(8, 2));
    o.clear();
	if (o >> temp_i && o.eof() && !o.fail() && temp_i > 0 && temp_i < 32)
		temp.day = temp_i;
	else
		std::cout << "invalid day" << std::endl;
	o.clear();
	return temp;
}
float BitcoinExchange::parse_value(std::string value)
{
	value = trim_ws(value);
	float temp_f = 0;
	std::istringstream o(value);
	if (o >> temp_f && o.eof() && !o.fail() && temp_f >= 0)
		return temp_f;
	else 
		return (-1);
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
	int i = 0;
	std::getline(csv, line);
	while(std::getline(csv, line))
	{
		size_t pos = line.find(delimeter);
		if (pos == std::string::npos)
		{
			std::cerr << "Error : Missing delimeter, row #" << i + 1 << " in " << file << std::endl;
			continue;
		}
		Date date = parse_date(line.substr(0, pos));
		float value = parse_value(line.substr(pos + 1, line.length() - pos));
		if (value == -1 )
		{
			std::cerr << "Error : Invalid value, row #" << i + 1<< " in " << file << std::endl;
			continue;
		}
		temp[date] = value;
		i++;
    }
	return temp;
}
std::ostream& operator<<( std::ostream& os, const Date& date ) {
	os << date.year << "-";
	(date.month < 10)? os << '0' << date.month: os << date.month;
	os << "-";
	(date.day < 10)? os << '0' << date.day: os << date.day;
    return (os);
}