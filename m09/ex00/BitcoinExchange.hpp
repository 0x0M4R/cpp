#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <utility>

class BitcoinExchange
{
    private:
        std::map <int,float> price;
        int price_flag;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange& operator=(BitcoinExchange const &copy);
        BitcoinExchange(BitcoinExchange const &copy);
        std::map <int,float> parse_csv (const char *file, char delimiter);
};
int parse_date(std::string date);
float parse_value(std::string value);
std::string trim_ws(std::string s);
int print_error(float value, std::string line);
#endif
