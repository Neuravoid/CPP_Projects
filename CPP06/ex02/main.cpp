#include "base.hpp"

int main(){
    Base b1;
    Base *bPtr = generate();
    identify(*bPtr);
    identify(bPtr);
    delete bPtr;
}