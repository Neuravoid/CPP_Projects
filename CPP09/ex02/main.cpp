#include "PmergeMe.hpp"

int main(int ac , char **av)
{
    if (ac < 2)
    {
        return 1;
    }
    try
    {
        PmergeMe p1;
        p1.initList(ac,av);
        p1.initVector(ac,av);
        p1.sayData('l');
        p1.sayData('v');   
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}