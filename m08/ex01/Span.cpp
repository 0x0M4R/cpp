#include "Span.hpp"

Span::Span( unsigned int n ) : _n( n ) {
}

Span::Span( const Span& src ) {
    *this = src;
}

Span& Span::operator=( Span const &rhs ) {
    if ( this != &rhs ) {
        this->_n = rhs._n;
        this->_list = rhs._list;
    }
    return *this;
}

Span::~Span( void ) {}


void Span::addNumber( int n ) {
    if ( _list.size() > _n )
        throw std::out_of_range("Span::addNumber: list is full");
    _list.push_back( n );
}

// void Span::addNumber( std::vector<int>::const_iterator itBegin, std::vector<int>::const_iterator itEnd ) {
//     if ( _list.size() > _n )
//         throw std::out_of_range("Span::addNumber: list is full");
//     _list.insert( _list.end(), itBegin, itEnd );
// }

// const std::vector< int >* Span::getList( void ) const {
//     return &_list;
// }

unsigned int    Span::longestSpan( void ) const
{
    // std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator> minmax;
    std::vector<int>::iterator min = std::min_element(_list.begin(), _list.end());
    // int max = minmax.second - minmax.first;
    std::cout << max << std::endl;
    return 0;
}


// unsigned int Span::shortestSpan( void ) const {
    // if ( _list.size() < 2 )
    //     throw std::out_of_range("Span::shortestSpan: list is empty");
    // unsigned int  min = Span::longestSpan();
    // for ( std::list<int>::const_iterator it = _list.begin(); it != _list.end(); ++it ) {
    //     for ( std::list<int>::const_iterator it2 = _list.begin(); it2 != _list.end(); ++it2 ) {
    //         if ( it == it2 ) continue;
    //         if ( std::abs( *it2 - *it ) <  static_cast< int >( min ) )
    //             min = std::abs( *it2 - *it );
    //     }
    // }
    // return min;
// }

// std::ostream& operator<<( std::ostream& os, const Span& span ) {
//     for ( std::list<int>::const_iterator it = span.getList()->begin(); it != span.getList()->end(); ++it )
//         os << *it << " ";
//     return os;
// }