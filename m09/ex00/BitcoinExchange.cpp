#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    price_flag = 0;
    price = parse_csv("./data.csv", ',');
    price_flag = 1;
    std::ifstream csv("./input.txt");
    std::string line;
	std::getline(csv, line); //skip header
	std::cout << line << std::endl;
	// int i = 0;
	while(std::getline(csv, line))
	{
		size_t pos = line.find('|');
		if (pos == std::string::npos)
		{
			// std::cerr << "Error : Missing delimeter, row #"  << std::endl;
			// continue;
		}
        int date = parse_date(line.substr(0, pos));
        if (date == -1 )
		{
			std::cerr << "Error: bad input => " << line.substr(0, pos) << std::endl;
			continue;
		}
		float value = parse_value(line.substr(pos + 1, line.length() - pos));
		if (value == -3 )
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
        if (value > 1000 )
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
        std::cout << price.lower_bound(date)->second.second * value<<std::endl;
    }
    // std::map <int,std::pair<int,float> > wallet = parse_csv("./input.txt", '|');
    // for(size_t i = 0;i<wallet.size();i++)
    // {

    //     std::cout << price.lower_bound(wallet[i].first)->second.second * wallet[i].second<<std::endl;
    //     // if (wallet[i].first
    //     // std::cout << i << " " << wallet[i].first << " " << wallet[i].second << "\n";
    // }
    // for(std::map<int, std::pair<int,float> >::const_iterator it = price.begin();
    //     it != price.end(); ++it)
    //         std::cout << it->first << " " << it->second.first << " " << it->second.second << "\n";

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
        return 1;
	if (date.length() != 10 )
        return -1;
    if (date.find_first_of('-') != 4)
        return 1;	
    if (date.find_last_of('-') != 7)
        return 1;	
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
        return -1;
    int month = (temp_i / 100) % year;
    if( month < 1 || month > 12)
        return -1;
    int day = temp_i % 100;
    if (day < 1 || day > 31)
        return -1;
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
	if (o >> temp_f && o.eof() && !o.fail() )
    {
        if(temp_f >= 0)
            return temp_f;
        else
            return -3;
    }
    // std::cout << "invalid value" << std::endl;
	return (-2);
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
			// std::cerr << "Error : Invalid date, row #" << i + 1<< " in " << file << std::endl;
			continue;
		}
		float value = parse_value(line.substr(pos + 1, line.length() - pos));
		if (value == -1 )
		{
			// std::cerr << "Error : Invalid value, row #" << i + 1<< " in " << file << std::endl;
			continue;
		}
        // (void)date;
        // (void)value;
        // temp.insert(i,std::make_pair(date,value));
        if (price_flag)
            temp[i] = std::make_pair(date,value);
        else
            temp[date] = std::make_pair(0,value);
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