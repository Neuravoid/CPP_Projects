#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain *brain;
    public:
        Cat();
        Cat(const Cat &ref);
        Cat& operator=(const Cat &ref);
        virtual ~Cat();

        virtual void makeSound() const;
        void setIdea(int i, std::string idea);
        std::string getIdea(int i) const;
};

#endif
