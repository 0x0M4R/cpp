#include "Span.hpp"

int main()
{
    try
    {
        Span s = Span(-1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    Span s = Span(1);
    s.addNumber(2);
    try
    {
        s.addNumber(6);
    }
    catch(std::exception &e)
    {
       std::cerr << e.what() << std::endl;
    }
    try
    {
        s.longestSpan();
    }
    catch(std::exception &e)
    {
       std::cerr << e.what() << std::endl;
    }
    
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::vector<int>    l( 10000 );
    srand( time ( NULL ) );
    std::generate( l.begin(), l.end(), std::rand);
    Span span( l.size() );
    span.addNumber( l.begin(), l.end() );
    std::cout << span.longestSpan() << std::endl;
    std::cout <<  span.shortestSpan() << std::endl;
    
    return 0;
}