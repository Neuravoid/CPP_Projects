#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    std::cout << "\n--- ARRAY TEST ---" << std::endl;
    const int num = 4;
    Animal* animals[num];

    for (int i = 0; i < num / 2; i++)
        animals[i] = new Dog();
    for (int i = num / 2; i < num; i++)
        animals[i] = new Cat();

    for (int i = 0; i < num; i++)
        delete animals[i];

    std::cout << "\n--- DEEP COPY TEST ---" << std::endl;
    Cat basic;
    basic.setIdea(0, "Miyav!");

    {
        Cat tmp = basic;
        tmp.setIdea(0, "Balik istiyorum!");
        std::cout << "Basic idea: " << tmp.getIdea(0) << std::endl;
    } // tmp burada siliyecek (destructor), eger shallow copy olsaydı basic.brain de giderdi.

    std::cout << "Basic idea: " << basic.getIdea(0) << std::endl;

    return 0;
}