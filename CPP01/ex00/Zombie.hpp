#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <cctype>
#include <string>
#include <iostream>
class Zombie
{
    private:
        std::string name;
    public:
        Zombie(std::string zombieName) : name(zombieName) {};
        void announce();
        ~Zombie(){std::cout << name << " is destroyed" << std::endl;}
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif