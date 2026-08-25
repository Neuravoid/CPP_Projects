#include "PmergeMe.hpp"


PmergeMe::PmergeMe(){

}

PmergeMe::~PmergeMe(){

}

PmergeMe& PmergeMe::operator=(const PmergeMe& ref){
    this->list = ref.list;
    this->vector = ref.vector;
    return *this;
}

PmergeMe::PmergeMe(const PmergeMe&ref){
    *this = ref;
}

void PmergeMe::initList(int ac, char **av){
    int nbr;
    while (ac != 1)
    {
        nbr = atol(av[ac-1]);
        if (nbr > INT_MAX || nbr < INT_MIN)
        {
            throw std::exception();
        }
        this->list.push_front(static_cast<int>(nbr));
        ac--;
    }
}

void PmergeMe::sortList(std::list<int>::,int length){
    int i = 0;
    while (i < length / 2)
    {
        if (*i1 < *i1+1)
        {
            
        }
        
    }
    
}


void PmergeMe::initVector(int ac, char **av){
    int nbr;
    int i = 1;
    while (ac != 1)
    {
        nbr = atol(av[i]);
        if (nbr > INT_MAX || nbr < INT_MIN)
        {
            throw std::exception();
        }
        this->vector.push_back(static_cast<int>(nbr));
        ac--;
        i++;
    }
}



void PmergeMe::sortVector(){
    
}


void PmergeMe::sayData(char type){
    if (type == 'l')
    {
        std::list<int>::iterator it = this->list.begin();
        std::list<int>::iterator ite = this->list.end();
        while (it != ite)
        {
            std::cout << *it << std::endl;
            it++;
        }
    }
    else if (type == 'v')
    {
        std::vector<int>::iterator it = this->vector.begin();
        std::vector<int>::iterator ite = this->vector.end();
        while (it != ite)
        {
            std::cout << *it << std::endl;
            it++;
        }
    }
    else
        std::cout << "wrong" << std::endl;
}