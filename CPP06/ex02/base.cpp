#include "base.hpp"
#include <cstdlib> 
#include <ctime>

Base::Base(){
    std::cout << "Base Created" << std::endl;
}

A::A(){
    std::cout << "A Created" << std::endl;
}

B::B(){
    std::cout << "B Created" << std::endl;
}

C::C(){
    std::cout << "C Created" << std::endl;
}

Base::~Base(){
    std::cout << "Base Destroyed" << std::endl;
}

A::~A(){
    std::cout << "A Destroyed" << std::endl;
}

B::~B(){
    std::cout << "B Destroyed" << std::endl;
}

C::~C(){
    std::cout << "C Destroed" << std::endl;
}


Base* generate(){
    std::srand(std::time(NULL));
    Base* mainPtr;
    int nbr = std::rand() % 3;
    if (nbr == 0)
        mainPtr = new A();      
    if (nbr == 1)
        mainPtr = new B();
    if (nbr == 2)
        mainPtr = new C();
    return mainPtr;
}

void identify(Base *p){
    if (dynamic_cast<A *>(p) != NULL)
    {
        std::cout << "This is class A" << std::endl;
    }   
    if (dynamic_cast<B *>(p) != NULL)
    {
        std::cout << "This is class B" << std::endl;
    }
    if (dynamic_cast<C *>(p) != NULL)
    {
        std::cout << "This is class C" << std::endl;
    }
  
}

void identify(Base &p)
{
    try{
        A& ref = dynamic_cast<A &>(p);
        (void)ref;
        std::cout << "This is class A" << std::endl;   
        return ;
    }
    catch(...)
    {
        try
        {
            B& ref = dynamic_cast<B &>(p);
            (void)ref;
            std::cout << "This is class B" << std::endl;   
            return ;
        }
        catch(...)
        {
            try
            {
                C& ref = dynamic_cast<C &>(p);
                (void)ref;
                std::cout << "This is class C" << std::endl; 
                return ;  
            }
            catch(...)
            {
                std::cerr << "Wrong" << std::endl;
            }
        }
    }
}