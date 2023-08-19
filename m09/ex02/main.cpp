#include "PmergeMe.hpp"

int main(int ac,char **av)
{
    if(ac < 2)
    {
        std::cout << "Error: invalid arguments." << std::endl;
        return 1;
    }
    PmergeMe rpn(av + 1, ac - 1);
    return 0;
}