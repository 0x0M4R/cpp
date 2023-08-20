#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}
PmergeMe::PmergeMe(char **input, int n)
{
    for(int i = 0; i < n; i++ )
    {
        int temp_i;
	    std::istringstream o(input[i]);
	    if (o >> temp_i && o.eof() && !o.fail() )
        {
            if(temp_i >= 0)
            {
                l.push_back(temp_i);
                d.push_back(temp_i);
            }
            else
            {
                std::cout << "Error : Only positive integers allowed" << std::endl;
                break ;
            }
        }
        else
        {
            std::cout << "Error : Invalid input" << std::endl;
            break ;
        }
        o.clear();
    }
    if (l.size() != (unsigned long)n)
        parse_error = 1;
    else
        parse_error = 0;
}
PmergeMe::PmergeMe(PmergeMe const &copy)
{
    *this=copy;
}
PmergeMe& PmergeMe::operator=( PmergeMe const &copy ) 
{
    if ( this != &copy ) {
        this->l = copy.l;
        this->d = copy.d;
        this->parse_error = copy.parse_error;
    }
    return *this;
}

void PmergeMe::execute()
{
    if(parse_error)
    {
        std::cout << "Error : Cannot execute because of parsing error!" <<std::endl;
        return ;
    }
    if(std::is_sorted(l.begin(), l.end()))
    {
        std::cout << "Error : Sequence already sorted!" <<std::endl;
        return ;
    }
    std::cout << "Before : ";
    for (std::list<int>::iterator i = l.begin(); i != l.end(); ++i)
        std::cout << *i << " ";
    std::cout << "\n";
    clock_t start1 = clock();
    l = sort_l(this->l);
    clock_t end1 = clock();
    double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;
    clock_t start2 = clock();
    d = sort_d(this->d);
    clock_t end2 = clock();
    double time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;
    std::cout << "After : ";
    for (std::list<int>::iterator i = l.begin(); i != l.end(); ++i)
        std::cout << *i << " ";
     std::cout << "\n";
    std::cout << "Time to process a range of " << l.size() << " elements with std::list container: " << time1 << " us" << std::endl;
    std::cout << "Time to process a range of " << d.size() << " elements with std::deque container: " << time2 << " us" << std::endl;
}

std::list<int> merge_l(std::list<int> left,std::list<int> right)
{
    std::list<int> result;
    while (!left.empty() || !right.empty())
	{
        if (right.empty() && !left.empty())
        {
            result.push_back(left.front());
            left.pop_front();
        }
        else if(left.empty() && !right.empty())
        {
            result.push_back(right.front());
            right.pop_front();
        }
        else if (left.front() <= right.front())
		{
            result.push_back(left.front());
            left.pop_front();
        }
		else
		{
            result.push_back(right.front());
            right.pop_front();
        }
    }
    return result;
}
std::list<int>  sort_l(std::list<int> k) 
{
    if (k.size() <= 1) return k;
    int mid = k.size() / 2;
    std::list<int> left(k.begin(),std::next(k.begin(),mid));
    std::list<int> right(std::next(k.begin(),mid),k.end());
    // Recursively sort the left and right halves
    left = sort_l(left);
    right = sort_l(right);
    std::list<int> result = merge_l(left,right);
    return result;
}
std::deque<int> merge_d(std::deque<int> left,std::deque<int> right)
{
    std::deque<int> result;
    while (!left.empty() || !right.empty())
	{
        if (right.empty() && !left.empty())
        {
            result.push_back(left.front());
            left.pop_front();
        }
        else if(left.empty() && !right.empty())
        {
            result.push_back(right.front());
            right.pop_front();
        }
        else if (left.front() <= right.front())
		{
            result.push_back(left.front());
            left.pop_front();
        }
		else
		{
            result.push_back(right.front());
            right.pop_front();
        }
    }
    return result;
}
std::deque<int>  sort_d(std::deque<int> k) 
{
    if (k.size() <= 1) return k;
    int mid = k.size() / 2;
    std::deque<int> left(k.begin(),std::next(k.begin(),mid));
    std::deque<int> right(std::next(k.begin(),mid),k.end());
    // Recursively sort the left and right halves
    left = sort_d(left);
    right = sort_d(right);
    std::deque<int> result = merge_d(left,right);
    return result;
}