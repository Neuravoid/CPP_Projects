#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    std::cout << "--- Subject Basic Test ---" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j; // should not create a leak
    delete i;

    std::cout << "\n--- Array of Animals Test ---" << std::endl;
    const int animalCount = 4;
    Animal* animals[animalCount];

    for (int k = 0; k < animalCount / 2; ++k)
        animals[k] = new Dog();
    for (int k = animalCount / 2; k < animalCount; ++k)
        animals[k] = new Cat();

    for (int k = 0; k < animalCount; ++k)
    {
        std::cout << "Animal[" << k << "] type: " << animals[k]->getType() << std::endl;
        animals[k]->makeSound();
    }

    for (int k = 0; k < animalCount; ++k)
        delete animals[k];

    std::cout << "\n--- Deep Copy Test ---" << std::endl;
    Dog basic;
    basic.setIdea(0, "I love bones");
    std::cout << "Basic dog's first idea: " << basic.getIdea(0) << std::endl;
    
    {
        Dog tmp = basic;
        std::cout << "Tmp dog created as copy of basic" << std::endl;
        std::cout << "Tmp dog's first idea: " << tmp.getIdea(0) << std::endl;
        tmp.setIdea(0, "I love cats");
        std::cout << "Tmp dog's first idea changed to: " << tmp.getIdea(0) << std::endl;
        std::cout << "Basic dog's first idea (should still be 'I love bones'): " << basic.getIdea(0) << std::endl;
    }
    std::cout << "Tmp dog destroyed, basic is still alive." << std::endl;
    std::cout << "Basic dog's first idea: " << basic.getIdea(0) << std::endl;

    return 0;
}
