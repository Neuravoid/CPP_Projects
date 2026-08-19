#include "iter.hpp"
#include <string>

void doubleIt(int &a){
    a = a * 2;
};

void printIt(const int a){
    std::cout << a << std::endl;
};

int getNumber(const int &a)
{
    std::cout << a << std::endl;
    return a;
};  

int main(){
    int arr[4] = {1,2,3,4};
    std::string arrst[4] = {"selam","naber","umut","alkan"};
    iter(arr,4,&doubleIt);
    iter(arr,4,&printIt);
    iter(arr,4,&getNumber);
    iter<std::string, void, std::string>(arrst, 4, Func);
}