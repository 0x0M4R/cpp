#include "whatever.hpp"

int main()
{
    int i = 2;
    int j = 1;
    std::cout << "i : " << i << " , j : " << j << std::endl;
    swap(i,j);
    std::cout << "i : " << i << " , j : " << j << std::endl;
}