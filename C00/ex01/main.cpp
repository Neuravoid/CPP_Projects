#include "Phonebook.hpp"
#include <iostream>

int main()
{
    PhoneBook   Rehber;
    std::string command;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if(!std::getline(std::cin, command))
            break;
        if (command == "ADD")
            Rehber.addContact();
        else if (command == "SEARCH")
            Rehber.searchContacts();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Hata: Gecersiz komut. (ADD, SEARCH, EXIT)" << std::endl;
    }
    return 0;
}
