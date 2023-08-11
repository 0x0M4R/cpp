#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    srand(time(NULL));

    std::list<int>    l( 10000 );
    srand( time ( NULL ) );
    std::generate( l.begin(), l.end(), std::rand);

    Span span( l.size() );

    span.addNumber( l.begin(), l.end() );

    std::cout << span.longestSpan() << std::endl;
    std::cout <<  span.shortestSpan() << std::endl;
    
    return 0;
}