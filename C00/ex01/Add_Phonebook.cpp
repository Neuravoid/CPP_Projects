#include "Phonebook.hpp"
#include <iostream>

PhoneBook::PhoneBook() {
    this->contactCount = 0;
}

static std::string check_input(int nbr)
{
    std::string input;

    std::cout << Contact::getLabelByIndex(nbr) << ": ";
    std::getline(std::cin, input);
    while (input.empty())
    {
        std::cout << "Hatali giris tekrar deneyiniz" << std::endl;
        std::cout << Contact::getLabelByIndex(nbr) << ": ";
        std::getline(std::cin, input);
    }
    return input;
}

void PhoneBook::addContact()
{
    Contact newContact;

    for (int i = 0; i < 5; i++)
        newContact.setFieldByIndex(i, check_input(i));

    if (contactCount < 8)
    {
        contacts[contactCount] = newContact;
        contactCount++;
    }
    else
    {
        for (int i = 0; i < 7; i++)
            contacts[i] = contacts[i + 1];
        contacts[7] = newContact;
    }
    std::cout << "Contact Added" << std::endl;
}
