#include "Zombie.hpp"

int main()
{
    Zombie *zombiePtr = zombieHorde(3,"ZombieName");
    delete[](zombiePtr);
}