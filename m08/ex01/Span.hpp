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
        std::vector<int>  _list;
        unsigned int    _n;
        Span();
    public:
        Span( unsigned int );
        Span( const Span& );
        ~Span( void );
        Span&               operator=( const Span& );
        void                addNumber( int );
        void                addNumber( std::vector<int>::const_iterator, std::vector<int>::const_iterator );
        unsigned int        longestSpan( void ) const;
        unsigned int        shortestSpan( void ) const;

        const std::vector< int >*   getList( void ) const;
};

std::ostream& operator<<( std::ostream&, const Span& );
#endif