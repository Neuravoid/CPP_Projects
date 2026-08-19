#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP


#include <stack>
#include <iostream>

template<typename T>
class MutantStack: public std::stack<T>{
    public:

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        MutantStack(){
            std::cout << "MutantStack Constructor Called" << std::endl; 
        }

        ~MutantStack(){
            std::cout << "MutantStack Destructor Called" << std::endl; 
        }

        MutantStack& operator=(const MutantStack& ref){
            std::stack<T>::operator=(ref);
            std::cout << "MutantStack Copy Assignment Operator Called" << std::endl; 
            return *this;
        }

        MutantStack(const MutantStack& ref): std::stack<T>(ref){
            std::cout << "MutantStack Copy Constructor Called" << std::endl;
        }

        iterator begin(){
            return this->c.begin();
        };

        iterator end(){
            return this->c.end();
        }

        const_iterator begin() const{
            return this->c.begin();
        };

        const_iterator end() const{
            return this->c.end();
        }
};


#endif