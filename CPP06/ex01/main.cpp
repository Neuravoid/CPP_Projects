#include "serialize.hpp"

int main(){
    Data d1("Umut");
    uintptr_t ui1 = Serializer::serialize(&d1);
    std::cout << ui1 << std::endl;
    Data* ptr = Serializer::deserialize(ui1);
    std::cout << &d1 << std::endl;
    std::cout << ptr << std::endl;
    std::cout << ptr->getName() << std::endl;
}