#include "Array.hpp"

#include <string>

int main(){
    std::string arr[4] = {"selam","naber","kanka","iyi"};
    Array<std::string> newarr(4);
    
    int i = 0;
    try
    {  
        Array<std::string> n2(newarr);
        while (i < 4)
        {
            std::cout << arr[i] << std::endl;
            newarr[i] = arr[i];
            std::cout << newarr[i] << std::endl;
            i++;
        }
        std::cout << newarr[-4] << std::endl;
        std::cout << n2.size() << std::endl;
        std::cout << newarr[1000] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}


