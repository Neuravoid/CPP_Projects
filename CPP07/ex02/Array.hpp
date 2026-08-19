#ifndef ARRAY_HPP
#define ARRAY_HPP


#include <string>
#include <iostream>
#include <exception>

template <typename T>

class Array{
    private:
        T* arr;
        int _size;
    public:
        Array();
        ~Array();
        Array(unsigned int n);
        Array(const Array& ref);
        Array& operator=(const Array& ref);
        T& operator[](int index);
        int size() const;
};

static int ft_abs(int size)
{
    if (size < 0)
        return (size*-1);
    return size;
}

template <typename T> 
Array<T>::Array(){
    std::cout << "Constructor Called." << std::endl;
    T* array = new T[0];
    this->_size = 0;
    this->arr = array;
}


template <typename T> 
Array<T>::Array(unsigned int n){
    std::cout << "Constructor Called." << std::endl;
    T* array = new T[n];
    this->_size = n;
    this->arr = array;
}


template <typename T> 
Array<T>::~Array(){
    delete[] this->arr;
    std::cout << "Destructor Called." << std::endl;
}

template <typename T> 
Array<T>& Array<T>::operator=(const Array<T>& ref){
    int i = 0;
    while (i < ft_abs(this->_size))
    {
        this->arr[i] = ref.arr[i];
        i++;
    }
    return *this;
}

template <typename T> 
Array<T>::Array(const Array<T>& ref){
    std::cout << "Copy Constructor Called." << std::endl;
    this->arr = new T[ref._size];
    this->_size = ref._size;
    *this = ref;
}


template <typename T> 
T& Array<T>::operator[](int index){
    if (this->_size < ft_abs(index))
        throw std::exception();
    else if (index < 0)
        return(this->arr[this->_size + index]);
    else
        return (this->arr[index]);    
}


template <typename T> 
int Array<T>::size() const{
    return(this->_size);
}

#endif