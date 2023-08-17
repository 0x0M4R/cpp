#include "RPN.hpp"

int main(int ac,char **av)
{
    if(ac != 2)
    {
        std::cout << "Error: invalid arguments." << std::endl;
        return 1;
    }
    BitcoinExchange B;
    B.parse_csv(av[1], '|');
    return 0;
}