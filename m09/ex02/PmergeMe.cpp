#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}
PmergeMe::PmergeMe(char **input, int n)
{
    int arr[n];
    for(int i = 0; i < n; i++ )
    {
        int temp_i;
	    std::istringstream o(input[i]);
	    if (o >> temp_i && o.eof() && !o.fail() )
        {
            if(temp_i >= 0)
                arr[i] = temp_i
            else
                return ;
        }
        std::cout << input[i] << std::endl;
    }
}
