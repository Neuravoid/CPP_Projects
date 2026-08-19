#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F, typename K>

void iter(T* arr, const int length_arr, F func(K params)){
    int i = 0;
    while (i < length_arr)
    {
        func(arr[i]);
        i++;
    }
};

template <typename K>

void Func(K params){
    std::cout << params << std::endl;
}

#endif