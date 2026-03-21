#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon{
    private:
        std::string type;

    public:
        Weapon();
        Weapon(const std::string &newType);
        const std::string &getType();
        void setType(const std::string &ref);
        ~Weapon();
};

#endif