#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <string>
#include <stdint.h>
#include <iostream>

class Data{
    private:
        std::string name;
    public:
        Data();
        ~Data();
        Data& operator=(const Data& ref);
        Data(const Data& ref);
        Data(const std::string name);
        std::string getName();

};

class Serializer{
    private:
        Serializer();
        ~Serializer();
        Serializer& operator=(const Serializer& ref);
        Serializer(const Serializer& ref);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

};  



#endif