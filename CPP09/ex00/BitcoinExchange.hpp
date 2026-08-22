#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <exception>
#include <stdlib.h>
#include <iomanip>

class BitcoinExchange{
    private:
        std::map<std::string,float> input;
        std::map<std::string,float> data;
        void getData(std::string fileName);
        void getInput(std::string fileName);
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& ref);
        BitcoinExchange(std::string fileName,std::string inputName);
        BitcoinExchange& operator=(const BitcoinExchange& ref);
        std::map<std::string,float>::iterator startPtr(char type);
        std::map<std::string,float>::iterator endPtr(char type);  
        std::map<std::string,float>::iterator returnBound(std::string date);
        int compareDates(std::string inputDate);
};

#endif