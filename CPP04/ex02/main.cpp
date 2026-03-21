#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    // Animal nesnesi üretilemez çünkü abstract yapildi
    Animal* nesne2 = new Dog();
    Animal* nesne3 = new Cat();

    nesne2->makeSound();
    nesne3->makeSound(); 

    delete nesne2;
    delete nesne3;

    return 0;
}