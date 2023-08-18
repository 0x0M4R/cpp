#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <algorithm>
#include <stack>
#include <iterator>
#include <deque>
template< typename T >
class MutantStack : public std::stack< T >
{
    public:
        MutantStack() {};
        virtual ~MutantStack() {};
        MutantStack( const MutantStack& rhs ) { *this = rhs; }
        MutantStack&    operator=( const MutantStack& rhs ) 
        {
            std::stack< T>::operator=( rhs );
            return *this;
        }
        
        typedef typename std::stack<T>::container_type::iterator    iterator;
        iterator    begin() { return this->c.begin(); }
        iterator    end() { return this->c.end(); }
};
#endif