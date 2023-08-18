#include "Span.hpp"

Span::Span(int n ) : 
_n((n < 0)? throw std::out_of_range("Exception : invalid size!"): n)
{
}

Span::Span( const Span& src ) 
{
    *this = src;
}

Span& Span::operator=( Span const &rhs ) 
{
    if ( this != &rhs ) {
        this->_n = rhs._n;
        this->_v = rhs._v;
    }
    return *this;
}

Span::~Span( void ) {}


void Span::addNumber( int n ) 
{
    if ( _v.size() >= _n )
        throw std::out_of_range("Exception : List is full!");
    _v.push_back( n );
}

void Span::addNumber( std::vector<int>::const_iterator itBegin, std::vector<int>::const_iterator itEnd ) {
    if ( _v.size() > _n )
        throw std::out_of_range("Span::addNumber: list is full");
    _v.insert( _v.end(), itBegin, itEnd );
}

unsigned int    Span::longestSpan( void ) const
{
    if ( _v.size() < 2 )
        throw std::out_of_range("Exception : List doesnt have enough elements!");
    return *std::max_element(_v.begin(), _v.end()) - *std::min_element(_v.begin(), _v.end());
}

unsigned int Span::shortestSpan( void ) const {
    if ( _v.size() < 2 )
        throw std::out_of_range("Exception : List doesnt have enough elements!");
    std::vector<int> temp(_v);
    std::sort(temp.begin(), temp.end());
    int min = longestSpan();
    for (size_t i=0; i < _v.size() ; i++ )
    {
        for (size_t j=0; j < _v.size() ; j++ )
        {
            if(_v[i] ==_v[j])
                continue;
            if (abs(_v[i] - _v[j]) < min)
                min = abs(_v[i] - _v[j]);
        }
    }
    return min;
}
