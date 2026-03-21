#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain& ref);
        Brain& operator=(const Brain& ref);
        ~Brain();

        void setIdea(int i, std::string text);
        std::string getIdea(int i) const;
};

#endif
