#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <iostream>
#include <limits.h>
#include <exception>
#include <stdlib.h>

class PmergeMe{
    private:
        std::vector<int>vector;
        std::list<int>list;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe& operator=(const PmergeMe& ref);
        PmergeMe(const PmergeMe& ref);
        
        void initVector(int ac, char **av);
        void initList(int ac, char **av);
        
        void sortVector();
        void sortList(std::list<int>::iterator i1,int length);

        void sayData(char type);
};





#endif