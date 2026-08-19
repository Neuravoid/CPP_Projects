#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
int easyfind(T cont, int x){
    typename T::iterator it = std::find(cont.begin(), cont.end(), x);
    if (cont.end() == it)
    {
        std::cout << "Not found" << std::endl;
        throw std::exception();
    }
    else
    {
        std::cout << "Founded:" << *it << std::endl;
        return *it;
    }
}


#endif
