#ifndef SCALARCONVERTER_HPP 
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& ref);
        ScalarConverter& operator=(const ScalarConverter& ref);
        
    public:
        static void convert(const std::string& literal);
};



#endif