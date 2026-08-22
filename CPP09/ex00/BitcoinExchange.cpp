#include "BitcoinExchange.hpp"

static bool checkDate(long year, long month, long day){
    if ((year > 2030 || year < 1990) ||
    (month > 12 || month < 1) ||
    (day < 1 || day > 31)
    )
        return 0; 

    if (
        ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31) ||
        (year % 4 == 0 && month == 2 && day > 29) ||
        (year % 4 != 0 && month == 2 && day > 28)
    )
        return 0;
    return 1;
}


int BitcoinExchange::compareDates(std::string inputDate)
{
    std::map<std::string,float>::iterator data_it = this->startPtr('d');
    std::string firstDate = data_it->first;

    int dyear = atol(firstDate.substr(0,firstDate.find("-")).c_str());
    int dmonth = atol(firstDate.substr(firstDate.find("-")+1,2).c_str());
    int dday = atol(firstDate.substr(firstDate.find("-")+4,2).c_str());

    int iyear = atol(inputDate.substr(0,inputDate.find("-")).c_str());
    int imonth = atol(inputDate.substr(inputDate.find("-")+1,2).c_str());
    int iday = atol(inputDate.substr(inputDate.find("-")+4,2).c_str());


    if ((dyear > iyear) ||  (iyear == dyear && imonth < dmonth) || (iyear == dyear && imonth == dmonth && iday < dday))
    {
        return 0;
    }
    return 1;
}


static int seperateAndSave(std::map<std::string,float>& mapExample,std::string line, char type,BitcoinExchange &be)
{
    int index = line.find(type);
    std::string leftPart;
    std::string rightPart;
    leftPart = line.substr(0,index);
    rightPart = line.substr(index+1);

    long year = atol(leftPart.substr(0,leftPart.find("-")).c_str());
    long month = atol(leftPart.substr(leftPart.find("-")+1,2).c_str());
    long day = atol(leftPart.substr(leftPart.find("-")+4,2).c_str());
    if (!checkDate(year,month,day))
    {
        std::cout << "Error: bad input => " << leftPart << std::endl; 
        return 1;
    }
    double fRight = atof(rightPart.c_str());
    if ((type == ',' && fRight > 2147483647 ) || (type == '|' && fRight > 1000))
    {
       std::cout << "Error: too large a number." << std::endl;
       return 1;
    }
    if ((type == ',' && fRight < 0 ) || (type == '|' && fRight  < 0))
    {
       std::cout << "Error: not a positive number." << std::endl;
       return 1;
    }
    if (type == '|' && !be.compareDates(leftPart))
    {
       std::cout << "Error: Bad input date." << std::endl;
       return 1;        
    }
    
    mapExample[leftPart] = static_cast<float>(fRight);
    return 0;
}

void BitcoinExchange::getData(std::string fileName)
{
    std::fstream file(fileName.c_str());
    if (!file)
    {
        std::cout << "Data File Couldn't Opened." << std::endl;
    }
    std::string line;
    std::getline(file,line);
    while (std::getline(file,line))
    {
        seperateAndSave(this->data,line,',',*this);
    }
}



std::map<std::string,float>::iterator BitcoinExchange::returnBound(std::string date){
    return(this->data.lower_bound(date));
}

void BitcoinExchange::getInput(std::string fileName)
{

    std::fstream file(fileName.c_str());
    if (!file)
    {
        std::cout << "Input File Couldn't Opened." << std::endl; 
    }
    float value;
    int result;
    std::map<std::string,float>::iterator data_it = this->startPtr('d');
    std::map<std::string,float>::iterator data_ite = this->endPtr('d');
    std::map<std::string,float>::iterator behindIt;
    std::string line;
    std::getline(file,line);
    if (line.compare("date | value") != 0)
    {
        std::cout << "File Has Wrong Header." << std::endl;
    }
    while (std::getline(file,line))
    {
        result = seperateAndSave(this->input,line,'|',*this);
        if (result == 0)
        {
            std::map<std::string,float>::iterator input_ite = this->endPtr('i');
            input_ite--;
            while (data_it != data_ite)
            {           
                if ((input_ite->first) == data_it->first)
                {                
                    value = input_ite->second * data_it->second;
                    std::cout << std::fixed << std::setprecision(2) << input_ite->first << " => " << input_ite->second << " = " << value << std::endl;
                    break;
                }
                data_it++;
            }
            if (input_ite->first != data_it->first)
            {
                behindIt =  this->returnBound(input_ite->first);
                behindIt--;
                value = behindIt->second * input_ite->second;
                std::cout << std::fixed << std::setprecision(2) << input_ite->first << " => " << input_ite->second << " = " << value << std::endl;
            }
        }
    }
}

BitcoinExchange::BitcoinExchange(){
    getData("data.csv");
    getInput("input.txt");
}

BitcoinExchange::BitcoinExchange(std::string fileName, std::string inputName){
    getData(fileName);
    getInput(inputName);
}

BitcoinExchange::~BitcoinExchange(){
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& ref){
    this->data = ref.data;
    return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& ref){
    this->data = ref.data;
}


std::map<std::string,float>::iterator BitcoinExchange::startPtr(char type){
    if (type == 'i')
        return(this->input.begin());
    return(this->data.begin());
    
}


std::map<std::string,float>::iterator BitcoinExchange::endPtr(char type){
    if (type == 'i')
        return(this->input.end());
    return(this->data.end());
}
