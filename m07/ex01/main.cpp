#include "iter.hpp"

void printer ( int &i)
{
    std::cout << i << std:: endl;
}
int main()
{
    int list[5] = {1,2,3,4,5};

    iter(list, 5,printer);
}