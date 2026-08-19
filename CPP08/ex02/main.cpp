#include "MutantStack.hpp"
#include <list>
int main()
{
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        std::cout << mstack.top() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::stack<int> s(mstack);
    }
    {
        std::list<int> lstack;
        lstack.push_back(5);
        lstack.push_back(17);
        std::cout << lstack.back() << std::endl;
        lstack.pop_back();
        std::cout << lstack.size() << std::endl;
        std::cout << lstack.back() << std::endl;
        lstack.push_back(3);
        lstack.push_back(5);
        lstack.push_back(737);
        lstack.push_back(0);
        std::list<int>::iterator it = lstack.begin();
        std::list<int>::iterator ite = lstack.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
    }
    {
        MutantStack<int> mstack;
        mstack.push(10);
        mstack.push(20);
        mstack.push(30);
        MutantStack<int> m2(mstack);     
        std::cout << m2.top() << std::endl;

        MutantStack<int> m3;
        m3 = mstack;                      
        std::cout << m3.top() << std::endl;
    }
}