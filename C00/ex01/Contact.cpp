#include "Contact.hpp"

Contact::Contact()
{
    error_flag = 0;
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
    if (value.empty())
    {
        error_flag = 1;
        return;
    }
    if (index == 3)
    {
        error_flag = 0;
        for (size_t i = 0; value[i]; i++)
        {
            if (value[i] < '0' || value[i] > '9')
            {
                error_flag = 1;
                return;
            }
        }
        phoneNumber = value;
        return;
    }
    error_flag = 0;
    if (index == 0) firstName = value;
    else if (index == 1) lastName = value;
    else if (index == 2) nickName = value;
    else if (index == 4) darkestSecret = value;
}

int Contact::getErrorFlag() const
{
    return this->error_flag;
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
