#include "Contact.hpp"

void Contact::setFirstName(const std::string &name)
{
    this->firstName = name;
}

std::string Contact::getFirstName() const
{
    return(this->firstName);
}

void Contact::setLastName(const std::string &name)
{
    this->lastName = name;
}

std::string Contact::getLastName() const
{
    return(this->lastName);
}

void Contact::setNickname(const std::string &name)
{
    this->nickName = name;
}

std::string Contact::getNickname() const
{
    return(this->nickName);
}

void Contact::setPhoneNumber(const std::string &number)
{
    this->phoneNumber = number;
}

std::string Contact::getPhoneNumber() const
{
    return(this->phoneNumber);
}

void Contact::setDarkestSecret(const std::string &secret)
{
    this->darkestSecret = secret;
}

std::string Contact::getDarkestSecret() const
{
    return(this->darkestSecret);
}

std::string Contact::getFieldByIndex(int index) const
{
    if (index == 0) return firstName;
    if (index == 1) return lastName;
    if (index == 2) return nickName;
    if (index == 3) return phoneNumber;
    if (index == 4) return darkestSecret;
    return "";
}

void Contact::setFieldByIndex(int index, const std::string &value)
{
    if (index == 0) firstName = value;
    else if (index == 1) lastName = value;
    else if (index == 2) nickName = value;
    else if (index == 3) phoneNumber = value;
    else if (index == 4) darkestSecret = value;
}

std::string Contact::getLabelByIndex(int index)
{
    if (index == 0) return "First Name";
    if (index == 1) return "Last Name";
    if (index == 2) return "Nickname";
    if (index == 3) return "Phone Number";
    if (index == 4) return "Darkest Secret";
    return "";
}
