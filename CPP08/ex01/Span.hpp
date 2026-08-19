#ifndef SPAN_HPP
#define SPAN_HPP


#include <vector>
#include <string>
#include <iostream>



class Span{
    private:
            int *N;
            int size;
            int currIndex;
    public:
        Span();
        Span(unsigned int n);
        ~Span();
        Span(const Span &ref);
        Span& operator=(const Span &ref);
        int operator[](int index);
        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
        int* getArr() const;
        int getSize() const;
        template<typename T>
        void addNumbers(T first, T end){
                while (first != end)
                {
                        addNumber(*first);
                        first++;
                }
        };
};

#endif