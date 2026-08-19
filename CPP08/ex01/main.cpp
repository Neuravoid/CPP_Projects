#include "Span.hpp"
int main(){
    try
    {
        Span sp(20);
        sp.addNumber(10);
        sp.addNumber(23);
        sp.addNumber(35);
        int i = 0;
        while (i < 3)
        {
            std::cout << sp[i] << std::endl;
            i++;
        }
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        Span sp2(sp);
        i = 0;
        while (i < 3)
        {
            std::cout << sp2[i] << std::endl;
            i++;
        }
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl; 
        // std::vector<int>vec;
        // vec.push_back(100);
        // vec.push_back(200);
        // vec.push_back(300);
        // vec.push_back(400);
        // std::vector<int>::const_iterator i1 = vec.begin();
        // std::vector<int>::const_iterator i2 = vec.end();
        // sp.addNumbers<std::vector<int>::const_iterator>(i1,i2);
        // i  = 0;
        // while (i < sp.getSize())
        // {
        //     std::cout << sp[i] << std::endl;
        //     i++;
        // }
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

}

