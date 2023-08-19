#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
// #include <fstream>
// #include <sstream>
#include <list>
#include <stack>
#include <algorithm>
// #include <utility>

class PmergeMe
{
    private:
        std::list<int> l;
        std::stack<int> s;
        PmergeMe();
    public:
        PmergeMe(char **input, int n);
        ~PmergeMe();
        PmergeMe& operator=(PmergeMe const &copy);
        PmergeMe(PmergeMe const &copy);
};
// std::ostream& operator<<( std::ostream&, const Date& );
#endif
