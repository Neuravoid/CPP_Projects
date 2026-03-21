#include "Zombie.hpp"
#include <iostream>

int main()
{
    //randomChump("selam");

    Zombie *ornek = newZombie("burda");
    ornek->announce();
    delete ornek;
}