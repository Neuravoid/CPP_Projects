#include "Phonebook.hpp"
#include <iostream>

PhoneBook::PhoneBook() {
    this->contactCount = 0;
}

static bool check_input(int nbr, std::string &input)
{
    std::cout << Contact::getLabelByIndex(nbr) << ": ";
    while (true)
    {
        if (!std::getline(std::cin, input))
            return false;        // EOF sinyali
        if (!input.empty())
            return true;         // Geçerli input
        std::cout << "Hatali giris tekrar deneyiniz" << std::endl;
        std::cout << Contact::getLabelByIndex(nbr) << ": ";
    }
}

void PhoneBook::addContact()
{
    Contact newContact;

    std::string fields[5];

    for (int i = 0; i < 5; i++)
    {
        while (true)
        {
            if (!check_input(i, fields[i]))
                return;
            newContact.setFieldByIndex(i, fields[i]);
            if (newContact.getErrorFlag() == 0)
                break;
            std::cout << "Hata: Gecersiz telefon numarasi. Sadece rakam giriniz." << std::endl;
        }
    }

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
