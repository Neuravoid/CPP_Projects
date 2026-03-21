#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie{
    private:
        std::string name;
    public:
        Zombie(): name("Unnamed") {}
        Zombie(std::string zombieName) : name(zombieName) {}
        void announce();
        void setName(std::string newName);
        ~Zombie() {std::cout << this->name << ": is destroyed" << std::endl;}
};

Zombie* zombieHorde( int N, std::string name);

#endif