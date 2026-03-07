#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

// UTF-8 string'in gerçek karakter sayısını döner (byte değil)
static size_t utf8Len(const std::string &s)
{
    size_t len = 0;
    for (size_t i = 0; i < s.size(); )
    {
        unsigned char c = s[i];
        if      (c < 0x80) i += 1;
        else if (c < 0xE0) i += 2;
        else if (c < 0xF0) i += 3;
        else               i += 4;
        len++;
    }
    return len;
}

// Karakter bazlı substr - Türkçe karakterleri ortadan kesmez
static std::string utf8Substr(const std::string &s, size_t maxChars)
{
    size_t chars = 0, i = 0;
    while (i < s.size() && chars < maxChars)
    {
        unsigned char c = s[i];
        if      (c < 0x80) i += 1;
        else if (c < 0xE0) i += 2;
        else if (c < 0xF0) i += 3;
        else               i += 4;
        chars++;
    }
    return s.substr(0, i);
}

// setw yerine: karakter sayısına göre padding ekler, her zaman tam 10 karakter genişlik
static void printPadded(const std::string &s)
{
    size_t len = utf8Len(s);
    size_t pad = (len < 10) ? (10 - len) : 0;
    for (size_t i = 0; i < pad; i++)
        std::cout << ' ';
    std::cout << s;
}

void PhoneBook::searchContacts() const
{
    if (contactCount == 0) {
        std::cout << "No contacts to display." << std::endl;
        return;
    }

    std::cout << "|     index| firstname|  lastname|  nickname|" << std::endl;

    for (int i = 0; i < contactCount; i++) {
        std::cout << "|" << std::setw(10) << i + 1 << "|";
        for (int j = 0; j < 3; j++) {
            std::string field = contacts[i].getFieldByIndex(j);
            if (utf8Len(field) > 10)
                field = utf8Substr(field, 9) + ".";
            printPadded(field);
            std::cout << "|";
        }
        std::cout << std::endl;
    }

    std::cout << "Enter the index of the contact to display: ";
    int index;
    if (!(std::cin >> index))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    if (index < 1 || index > contactCount) {
        std::cout << "Invalid index." << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cin.ignore();
    const Contact &contact = contacts[index - 1];
    for (int j = 0; j < 5; j++)
        std::cout << Contact::getLabelByIndex(j) << ": " << contact.getFieldByIndex(j) << std::endl;
}