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
        this->_list = rhs._list;
    }
    return *this;
}

Span::~Span( void ) {}


void Span::addNumber( int n ) 
{
    if ( _list.size() >= _n )
        throw std::out_of_range("Exception : List is full!");
    _list.push_back( n );
}

void Span::addNumber( std::vector<int>::const_iterator itBegin, std::vector<int>::const_iterator itEnd ) {
    if ( _list.size() > _n )
        throw std::out_of_range("Span::addNumber: list is full");
    _list.insert( _list.end(), itBegin, itEnd );
}

const std::vector< int >* Span::getList( void ) const {
    return &_list;
}

unsigned int    Span::longestSpan( void ) const
{
    if ( _list.size() < 2 )
        throw std::out_of_range("Exception : List doesnt have enough elements!");
    // std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator> minmax;
    // std::vector<int>::const_iterator min = std::min_element(_list.begin(), _list.end());
    // std::pair<int,int> minmax;
    // minmax = std::minmax(_list)
    // // int max = minmax.second - minmax.first;
    // std::cout << min << std::endl;
    return *std::max_element(_list.begin(), _list.end()) - *std::min_element(_list.begin(), _list.end());

    // std::cout << *std::min_element(_list.begin(), _list.end());
}


unsigned int Span::shortestSpan( void ) const {
    if ( _list.size() < 2 )
        throw std::out_of_range("Exception : List doesnt have enough elements!");
    std::vector<int> temp(_list);
    std::sort(temp.begin(), temp.end());
    // for (std::vector<int>::iterator it1 = temp.begin(); it1 != temp.end(); it1++ )
    // {
    int min = longestSpan();
    for (size_t i=0; i < _list.size() ; i++ )
    {
        for (size_t j=0; j < _list.size() ; j++ )
        {
            if(_list[i] ==_list[j])
                continue;
            if (abs(_list[i] - _list[j]) < min)
                min = abs(_list[i] - _list[j]);
            
            // std::cout << _list[i] << " " << _list[j] << std::endl;
            // std::cout << _list[i] - _list[j] << std::endl;
        }
    }
        // for (std::vector<int>::iterator it2 = temp.begin(); it2 != temp.end(); it2++ )
        // {
        //     if ( *it1 == *it2)
        //         continue;
        //     std::cout << *it1 << " " << *it2 << std::endl;
        // }
        // std::cout << *it  << std::endl;
    // }
    return min;
}

// std::ostream& operator<<( std::ostream& os, const Span& span ) {
//     for ( std::list<int>::const_iterator it = span.getList()->begin(); it != span.getList()->end(); ++it )
//         os << *it << " ";
//     return os;
// }