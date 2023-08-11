#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>
template <typename T>
void iter(T *arr, int size, void (*func)( T &))
{
    for (int i=0; i < size;i++)
        func( arr[i]);
}

#endif