#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

struct Time
{
    int year;
    int month;
    int day;
};

class BitcoinExchange
{
    private:
        std::map <std::string, float> price;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange& operator=(BitcoinExchange const &copy);
        BitcoinExchange(BitcoinExchange const &copy);

        std::map<std::string, float> getData();
        std::vector<std::string> splitString(std::string str, char delimiter);
};
#endif
