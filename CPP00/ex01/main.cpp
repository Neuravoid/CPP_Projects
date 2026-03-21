#include "Phonebook.hpp"
#include <iostream>

int main()
{
    PhoneBook   Rehber;
    std::string command;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if (command == "ADD")
            Rehber.addContact();
        else if (command == "SEARCH")
            Rehber.searchContacts();
        else if (command == "EXIT")
            break;
    }
    return 0;
}
