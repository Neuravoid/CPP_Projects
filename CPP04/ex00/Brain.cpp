#include "Brain.hpp"

Brain::Brain() {
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "Empty Idea";
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& ref) {
    *this = ref;
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& ref) {
    if (this != &ref) {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = ref.ideas[i];
    }
    std::cout << "Brain assignment operator called" << std::endl;
    return (*this);
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int i, std::string text) {
    if (i >= 0 && i < 100)
        this->ideas[i] = text;
}

std::string Brain::getIdea(int i) const {
    if (i >= 0 && i < 100)
        return (this->ideas[i]);
    return ("");
}
