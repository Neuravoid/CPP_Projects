#include "Harl.hpp"
int main(int ac, char **av)
{
    if (ac != 2 || !av[1])
        return 1;

    std::string str = std::string(av[1]); 
    if (!(str == "DEBUG" || str == "INFO" || str ==  "WARNING" || str == "ERROR" ))
        return 1;
    
    Harl harl;
    harl.complain(av[1]);

}