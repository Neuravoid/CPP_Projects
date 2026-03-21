#include "Dog.hpp"

Dog::Dog() : Animal() {
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &ref) : Animal(ref) {
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = new Brain(*(ref.brain));
}

Dog& Dog::operator=(const Dog &ref) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &ref) {
        this->type = ref.type;
        delete this->brain;
        this->brain = new Brain(*(ref.brain));
    }
    return (*this);
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof Woof..." << std::endl;
}

void Dog::setIdea(int i, std::string idea) {
    if (this->brain)
        this->brain->setIdea(i, idea);
}

std::string Dog::getIdea(int i) const {
    if (this->brain)
        return (this->brain->getIdea(i));
    return ("");
}
