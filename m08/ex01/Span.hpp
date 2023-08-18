#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <list>
class Span
{
    private:
        std::vector<int>  _v;
        unsigned int    _n;
        Span();
    public:
        Span( int n);
        Span( const Span& );
        ~Span( void );
        Span&               operator=( const Span& );
        void                addNumber( int );
        void                addNumber( std::vector<int>::const_iterator, std::vector<int>::const_iterator );
        unsigned int        longestSpan( void ) const;
        unsigned int        shortestSpan( void ) const;

};
#endif