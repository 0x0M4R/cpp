#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

struct Date
{
    int year;
    int month;
    int day;
};

class BitcoinExchange
{
    private:
        std::map <Date, float> price;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange& operator=(BitcoinExchange const &copy);
        BitcoinExchange(BitcoinExchange const &copy);
        std::map <Date,float> parse_csv (const char *file, char delimiter);
        Date parse_date(std::string date);
};
#endif
