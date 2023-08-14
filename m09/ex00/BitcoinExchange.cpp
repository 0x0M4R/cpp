#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    price = parse_csv("./data.csv", ',');
    std::map <int,std::pair<int,float> > wallet = parse_csv("./input.txt", '|');
    for(std::map <int,std::pair<int,float> >::const_iterator it = wallet.begin();
    it != wallet.end(); ++it)
    {
        std::cout << it->first << " " << it->second.first << " " << it->second.second << "\n";
    }
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
int BitcoinExchange::parse_date(std::string date)
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
	int temp_i;
    date.erase(std::remove(date.begin(), date.end(), '-'), date.end());
    // std::cout << date << std::endl;
    // (void)temp_i;
	std::istringstream o(date);
    if (o >> temp_i && o.eof() && !o.fail())
		;
    else
	    std::cout << "invalid date : must be numbers" << std::endl;
    int year = temp_i/10000;
    if( year < 0 || year > 9999 )
        std::cout << "invalid year : must be positive" << std::endl;
    int month = (temp_i / 100) % year;
    if( month < 1 || month > 12)
        std::cout << "invalid month : must be between 1-12" << std::endl;
    int day = temp_i % 100;
    if (day < 1 || day > 31)
                std::cout << "invalid month : must be between 1-31" << std::endl;
    return temp_i;
	// o.str(date.substr(5, 2));
	// if (o >> temp_i && o.eof() && !o.fail() && temp_i > 0 && temp_i < 13)
	// 	temp.month = temp_i;
	// else
	// 	std::cout << "invalid month" << std::endl;
	// o.str(date.substr(8, 2));
    // o.clear();
	// if (o >> temp_i && o.eof() && !o.fail() && temp_i > 0 && temp_i < 32)
	// 	temp.day = temp_i;
	// else
	// 	std::cout << "invalid day" << std::endl;
	// o.clear();
}
float BitcoinExchange::parse_value(std::string value)
{
	value = trim_ws(value);
	float temp_f = 0;
	std::istringstream o(value);
	if (o >> temp_f && o.eof() && !o.fail() && temp_f >= 0)
		return temp_f;
    std::cout << "invalid value" << std::endl;
	return (-1);
}
std::map <int,std::pair<int,float> > BitcoinExchange::parse_csv(const char *file, char delimeter)
{
	std::map <int,std::pair<int,float> > temp;
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
		int date = parse_date(line.substr(0, pos));
        if (date == -1 )
		{
			std::cerr << "Error : Invalid date, row #" << i + 1<< " in " << file << std::endl;
			continue;
		}
		float value = parse_value(line.substr(pos + 1, line.length() - pos));
		if (value == -1 )
		{
			std::cerr << "Error : Invalid value, row #" << i + 1<< " in " << file << std::endl;
			continue;
		}
        // (void)date;
        // (void)value;
        // temp.insert(i,std::make_pair(date,value));
		temp[i] = std::make_pair(date,value);
        // std::cout << date << " "<< temp[date] << std::endl;
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