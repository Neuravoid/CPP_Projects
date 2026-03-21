#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string> 
#include <iostream>

class WrongAnimal{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &animal);
        WrongAnimal& operator=(const WrongAnimal &animal);
        virtual ~WrongAnimal(); // sor bunu . virtual kalkmalı mı ?

        void makeSound() const;
        std::string getType() const;
};

#endif