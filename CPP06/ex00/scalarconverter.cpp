#include "scalarconverter.hpp"
#include <iostream>
#include <stdlib.h>
#include <climits>
#include <limits>
#include <float.h>

static bool isDigit(const char c){
    if (c-'0' <= 9 && c-'0' >= 0)
        return 1;
    return 0;
}

static bool isChar(const std::string &ref){
    if (!(' ' <= ref[0] && ref[0] <= '~'))
    {
        return 0;
    }
    return 1;
} 

static int countChar(const std::string &ref, char target){
    int i = 0;
    int count = 0;
    while (ref[i])
    {

        if (ref[i] == target)
        {
            count++;
        }
        i++;
    }
    return count;
}

static bool isString(const std::string &ref){
    int i = 0;
    if (ref.length() == 1)
        return 0;
    while (ref[i])
    {
        if (isChar(&ref[i]))
        {
            i++;
        }
        else
        {
            std::cerr << "Non-displayable" << std::endl;
            return 0;
        }
    }
    return 1;
} 

static bool isInt(const std::string &ref){
    int i = 0;
    if (ref[i] == '+' || ref[i] == '-')
        i++;
    
    while (ref[i])
    {
        if (isDigit(ref[i]) && ref[i] != '.' && ref[i] != 'f')
        {
            i++;
            continue;            
        }
        return 0;
    }
    return 1;
}

static bool isFloat(const std::string &ref){
    int i = 0;
    if (ref == "nanf" || ref == "+inff" || ref == "-inff")
        return 1;
    if (ref[i] == '+' || ref[i] == '-')
        i++;
    if (ref.end()[-1] == 'f' && countChar(ref,'.') == 1 && countChar(ref,'f') == 1)
    {
        while (ref[i])
        {
            if (!(ref[i] == 'f' || ref[i] == '.' || isDigit(ref[i])))
                return 0;
            else
                i++;
        }
        return 1;
    }
    return 0;
}

static bool isDouble(const std::string &ref){
    int i = 0;
    if (ref == "nan" || ref == "+inf" || ref == "-inf")
        return 1;
    if (ref[i] == '+' || ref[i] == '-')
        i++;
    if (ref.end()[-1] != 'f' && countChar(ref,'.') == 1)
    {
        while (ref[i])
        {
            if (!(ref[i] == '.' || isDigit(ref[i])))
                return 0;
            else
                i++;
        }
        return 1;
    }
    return 0;
}


bool has_fraction(float num) {
    return (num != static_cast<long>(num)); 
}

static void printAll(const int inbr, const float fnbr, const double dnbr, const char cnbr, char type)
{
    if (type != 's')
    {
        if (32 <= cnbr && cnbr <= 126 && inbr <= 256)
            std::cout << "char: " << "'" << cnbr << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << inbr << std::endl;           
        if (has_fraction(fnbr))
        {
            std::cout << "float: " << fnbr << "f" << std::endl;
            std::cout << "double: " << dnbr << std::endl;  
        }
        else
        {
            std::cout << "float: " << fnbr << ".0f" << std::endl;
            std::cout << "double: " << dnbr << ".0" << std::endl;              
        }
    }
    else
    {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
    }
}

static void transformIntoTypes(const std::string &ref, char t)
{
    int inbr;
    float fnbr;
    double dnbr;
    char cnbr;
    if (t == 'i')
    {
        inbr = atoi(ref.c_str());
        fnbr = static_cast<float>(inbr);      
        dnbr = static_cast<double>(inbr);
        cnbr = static_cast <char>(inbr);
    }
    else if(t == 'f')
    {
        fnbr = atof(ref.c_str());
        inbr = static_cast<int>(fnbr);
        dnbr = static_cast<double>(fnbr);
        cnbr = static_cast<char>(fnbr);
    }
    else if(t == 'd')
    {
        dnbr = atof(ref.c_str());
        inbr = static_cast<int>(dnbr);
        fnbr = static_cast<float>(dnbr);
        cnbr = static_cast<char>(dnbr);
    }
    else if(t == 'c')
    {
        cnbr = static_cast<char>(ref[0]);
        inbr = static_cast<int>(cnbr);
        fnbr = static_cast<float>(cnbr);
        dnbr = static_cast<double>(cnbr);
    }
    printAll(inbr,fnbr,dnbr,cnbr,t);
}

void ScalarConverter::convert(const std::string& ref)
{
    if (ref.length() == 1 && isChar(ref) && !isDigit(ref[0]))
    {
        transformIntoTypes(ref,'c');
    }
    else if (isDouble(ref))
    {
        if (ref == "nan" || ref == "+inf" || ref == "-inf")
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            if (ref != "nan")
            {
                std::cout << "float: "<< ref.substr(0,4)+"f" << std::endl;
                std::cout << "double: " << ref.substr(0,4) << std::endl;
            }
            else
            {
                std::cout << "float: "<< ref.substr(0,3)+"f" << std::endl;
                std::cout << "double: " << ref.substr(0,3) << std::endl;       
            }

        }
        else{
            double nbr = atof(ref.c_str());
            if (nbr >= std::numeric_limits<double>::infinity() || nbr <= -1*std::numeric_limits<double>::infinity())
                std::cout << "This will occurse an overflow. Program has been stopped. Number: " << ref << std::endl;   
            else       
                transformIntoTypes(ref,'d');
        }

    }
    else if (isFloat(ref))
    {
        if (ref == "nanf" || ref == "+inff" || ref == "-inff")
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            if (ref != "nanf")
            {
                std::cout << "float: "<< ref.substr(0,5) << std::endl;
                std::cout << "double: " << ref.substr(0,4) << std::endl;
            }
            else
            {
                std::cout << "float: "<< ref.substr(0,3)+"f" << std::endl;
                std::cout << "double: " << ref.substr(0,3) << std::endl;       
            }

        }
        else{
            double nbr = atof(ref.c_str());
            if (nbr >= std::numeric_limits<float>::max() || nbr <= -1*std::numeric_limits<float>::max())
            {
                std::cout << "This will occurse an overflow. Program has been stopped. Number: " << ref << std::endl;   
            }
            else
                transformIntoTypes(ref,'f');        
        }
    }
    else if (isInt(ref))
    {
        long nbr = atol(ref.c_str());
        if (nbr >= INT_MAX || nbr <= INT_MIN)
        {
            std::cout << "This will occurse an overflow. Program has been stopped. Number: " << ref << std::endl;   
        }
        else
        {
            transformIntoTypes(ref,'i');           
        }
    }
    else if (isString(ref))
    {
        transformIntoTypes(ref,'s');
    }
    else
        std::cerr << "Error" << ref << std::endl;

}