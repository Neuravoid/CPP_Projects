#ifndef BASE_HPP
#define BASE_HPP


#include <iostream>

class Base{
    private:

    public:
        Base();
        virtual ~Base();
};

class A: public Base{
    private:
    public:
        A();
        ~A();

};

class B: public Base{
    private:
    public:
        B();
        ~B();    
};

class C: public Base{
    private:
    public:
        C();
        ~C();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif