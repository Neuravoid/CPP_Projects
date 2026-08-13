#include "serialize.hpp"

Data::Data(){
    this->name="Empty";
    std::cout << "Data created" << std::endl;
}

Data::~Data(){
    std::cout << "Data destroyed" << std::endl;
}

Data::Data(const Data& ref){
    *this = ref;
}

Data::Data(const std::string name){
    this->name = name;
    std::cout << "Data created" << std::endl;
}

Data& Data::operator=(const Data &ref){
    this->name = ref.name;
    return *this;
}   

std::string Data::getName(){
    return this->name;
}


uintptr_t Serializer::serialize(Data* ptr){
    uintptr_t intPtr = reinterpret_cast<uintptr_t>(ptr);
    return intPtr;
}

Data* Serializer::deserialize(uintptr_t raw){
    Data* ptr = reinterpret_cast<Data *>(raw);
    return ptr;
}