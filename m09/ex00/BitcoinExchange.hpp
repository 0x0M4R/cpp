#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <utility>
struct Date
{
    int year;
    int month;
    int day;
};

class BitcoinExchange
{
    private:
        std::map <int,std::pair<int,float> > price;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange& operator=(BitcoinExchange const &copy);
        BitcoinExchange(BitcoinExchange const &copy);
        std::map <int,std::pair<int,float> > parse_csv (const char *file, char delimiter);
        int parse_date(std::string date);
        float parse_value(std::string value);
        std::string trim_ws(std::string s);
};
std::ostream& operator<<( std::ostream&, const Date& );
#endif