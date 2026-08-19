#include "Span.hpp"
#include "limits.h"
int ft_abs(int n){
    if (n < 0)
        return n*-1;
    return n;
}

Span::Span(){
    this->N = new int[0];
    this->size = 0;
    this->currIndex = 0;
    std::cout << "Constructor Called" << std::endl;
}


Span::Span(unsigned int n){
    this->N = new int[n];
    this->size = n;
    this->currIndex = 0;
    std::cout << "Constructor Called" << std::endl;
}

int Span::operator[](int index){
    if (this->size < ft_abs(index))
        throw std::exception();
    else if (index < 0)
        return(this->N[this->size + index]);
    else
        return (this->N[index]);   
}

Span::~Span(){
    delete[] this->N;
    std::cout << "Destructor Called" << std::endl;
}

Span& Span::operator=(const Span& ref){
    this->N = new int[ref.getSize()];
    this->size = ref.getSize();
    int i = 0;
    while (i < ref.getSize())
    {
        this->N[i] = ref.N[i];
        i++;
    }
    this->currIndex = ref.currIndex;
    return *this;
}

Span::Span(const Span& ref){
    std::cout << "Copy Constructor Called" << std::endl;
    *this = ref;
}

void Span::addNumber(int n){
    if (this->currIndex >= this->size)
        throw std::exception();
    this->N[this->currIndex] = n;
    this->currIndex++;
}

int Span::shortestSpan(){
    if (this->getSize() < 2)
        throw std::exception();

    int* array = this->N;
    int i = 0 ;
    int j = 0 ;
    int shortest = INT_MAX;
    while (i < this->currIndex)
    {
        j = 0;
        while (j < this->currIndex)
        {
            if (i != j)
            {
                int calc = ft_abs(array[i] - array[j]) ;
                if (calc < shortest)
                    shortest = calc;
            }
            j++;
        }
        i++;
    }
    return shortest;
}




int Span::longestSpan(){
    if (this->getSize() < 2)
        throw std::exception();

    int* array = this->N;
    int i = 0 ;
    int j = 0 ;
    int longest = INT_MIN;
    while (i < this->currIndex)
    {
        j = 0;
        while (j < this->currIndex)
        {
            if (i != j)
            {
                int calc = ft_abs(array[i] - array[j]) ;
                if (calc > longest)
                    longest = calc;
            }
            j++;
        }
        i++;
    }
    return longest;
}

int *Span::getArr() const{
    return this->N;
}

int Span::getSize() const{
    return this->size;
}