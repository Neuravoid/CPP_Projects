#include "Phonebook.hpp"
#include <iostream>
#include <iomanip> // setw, right kullanımı için
#include <limits>  // numeric_limits için

void PhoneBook::searchContacts() const
{
    if (contactCount == 0) {
        std::cout << "No contacts to display." << std::endl;
        return;
    }

    // Başlıkları yazdır
    std::cout << "|     index| firstname|  lastname|  nickname|" << std::endl;

    // Kişileri listele
    for (int i = 0; i < contactCount; i++) {
        std::cout << "|" << std::setw(10) << i + 1 << "|";

        for (int j = 0; j < 3; j++) { // Sadece firstName, lastName, nickname
            std::string field = contacts[i].getFieldByIndex(j);
            if (field.length() > 10)
                field = field.substr(0, 9) + ".";
            std::cout << std::setw(10) << field << "|";
        }
        std::cout << std::endl;
    }

    // Kullanıcıdan index al
    std::cout << "Enter the index of the contact to display: ";
    int index;
    std::cin >> index;

    // Geçersiz index kontrolü
    if (std::cin.fail() || index < 1 || index > contactCount) {
        std::cout << "Invalid index." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cin.ignore();
    // Detayları göster
    const Contact &contact = contacts[index - 1];
    for (int j = 0; j < 5; j++)
        std::cout << Contact::getLabelByIndex(j) << ": " << contact.getFieldByIndex(j) << std::endl;
}