#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
// #include <fstream>
#include <sstream>
#include <list>
#include <deque>
#include <algorithm>
#include <iterator>
// #include <utility>

class PmergeMe
{
    private:
        std::list<int> l;
        std::deque<int> d;
        bool parse_error;
        PmergeMe();
    public:
        PmergeMe(char **input, int n);
        ~PmergeMe();
        PmergeMe& operator=(PmergeMe const &copy);
        PmergeMe(PmergeMe const &copy);
        void execute();
        // std::list<int> sort_l(std::list<int> k);
};
std::list<int> sort_l(std::list<int> k);
std::deque<int> sort_d(std::deque<int> k);
std::list<int> merge_l(std::list<int> left,std::list<int> right);
std::deque<int> merge_d(std::deque<int> left,std::deque<int> right);
// std::ostream& operator<<( std::ostream&, const Date& );
#endif
