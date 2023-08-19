#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
// #include <fstream>
// #include <sstream>
#include <vector>
// #include <algorithm>
// #include <utility>

class RPN
{
    private:
        std::vector<int> v;
    public:
        RPN();
        RPN(char *input);
        ~RPN();
        RPN& operator=(RPN const &copy);
        RPN(RPN const &copy);
};
// std::ostream& operator<<( std::ostream&, const Date& );
#endif
