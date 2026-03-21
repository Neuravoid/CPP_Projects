#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain *brain;
    public:
        Dog();
        Dog(const Dog &ref);
        Dog& operator=(const Dog &ref);
        virtual ~Dog();

        virtual void makeSound() const;
        void setIdea(int i, std::string idea);
        std::string getIdea(int i) const;
};

#endif
