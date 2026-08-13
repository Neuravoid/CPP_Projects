#include <iostream>
#include "scalarconverter.hpp"
int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cerr << "Wrong Argument Count, You have to use only 2" << std::endl;
        return -1;
    }
    std::string a = static_cast<std::string>(av[1]);
    // std::cout << a.end()[-2] << std::endl;
    ScalarConverter::convert(av[1]);
    
}
