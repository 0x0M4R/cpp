#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    price_flag = 0;
    price = parse_csv("./data.csv", ',');
    price_flag = 1;
}
BitcoinExchange::~BitcoinExchange()
{
}
std::map <int,float>  BitcoinExchange::parse_csv(const char *file, char delimeter)
{
	std::map <int,float> temp;
	std::ifstream csv(file);
    if (!csv.is_open())
		return temp; //fix incase data.csv doesnt open
    std::string line;
	std::getline(csv, line); //skip header /need fix
	int i = 0;
	while(std::getline(csv, line))
	{
        std::string::difference_type n = std::count(line.begin(), line.end(), delimeter);
        if (n > 1)
            print_error(-5,"");
		size_t pos = line.find(delimeter);
        //check pos for delimiter
		int date = parse_date(line.substr(0, pos));
		float value = parse_value(line.substr(pos + 1, line.length() - pos));

        if (price_flag)
        {
            if(date == -1)
            {
                print_error(date,line.substr(0, pos));
                continue;
            }
            if (pos == std::string::npos)
            {
                std::cout<<"Error: missing delimiter"<< std::endl;
                continue;
            }
            if(print_error(value,""))
                continue;

            std::cout << line.substr(0, pos) << " => " << value << " = "<<price.lower_bound(date)->second * value<<std::endl;
        }
        else
            temp[date] = value;
		i++;
    }
	return temp;
}
std::string trim_ws(std::string s)
{
	const char* ws = " \t\r";
	s.erase(s.find_last_not_of(ws) + 1);
	s.erase(0, s.find_first_not_of(ws));
	return s;
}
int parse_date(std::string date)
{
	date = trim_ws(date);
	std::string::difference_type n = std::count(date.begin(), date.end(), '-');
	if (n != 2)
        return -1;
	if (date.length() != 10 )
        return -1;
    if (date.find_first_of('-') != 4)
        return -1;	
    if (date.find_last_of('-') != 7)
        return -1;	
    int temp_i;
    date.erase(std::remove(date.begin(), date.end(), '-'), date.end());
	std::istringstream o(date);
    if (o >> temp_i && o.eof() && !o.fail())
		;
    else
        return -1;
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

}
float parse_value(std::string value)
{
    if(!value.length())
    {
        return -4;
    }
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
	return (-2);
}
int print_error(float value, std::string line)
{

    if (value == -1 )
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return 1;
    }
    if (value == -3 )
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return 1;
    }
    if (value == -4 )
    {
        std::cerr << "Error: no value found." << std::endl;
        return 1;
    }
    if (value == -2 )
    {
        std::cerr << "Error: invalid value." << std::endl;
        return 1;
    }
    if (value > 1000 )
    {
        std::cerr << "Error: too large a number." << std::endl;
        return 1;
    }
    if (value == -5 )
    {
        std::cerr << "Error: multiple demiters." << std::endl;
        return 1;
    }
    return 0;
}

// std::ostream& operator<<( std::ostream& os, const Date& date ) {
// 	os << date.year << "-";
// 	(date.month < 10)? os << '0' << date.month: os << date.month;
// 	os << "-";
// 	(date.day < 10)? os << '0' << date.day: os << date.day;
//     return (os);
// }