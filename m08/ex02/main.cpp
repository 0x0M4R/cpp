#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top : " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size : " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    std::cout << "is empty : " << mstack.empty() << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::cout << std::endl;
    std::stack<int>  s(mstack);
    mstack.push(100);
    std::cout << "size of s : " << s.size() << std::endl;
    s.swap(mstack);
    std::cout << "size of s : " << s.size() << std::endl;
    return 0;
}