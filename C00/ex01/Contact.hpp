#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;
    
public:
    void setFirstName(const std::string &name);
    std::string getFirstName() const;

    void setLastName(const std::string &name);
    std::string getLastName() const;

    void setNickname(const std::string &name);
    std::string getNickname() const;

    void setPhoneNumber(const std::string &number);
    std::string getPhoneNumber() const;

    void setDarkestSecret(const std::string &secret);
    std::string getDarkestSecret() const;

    std::string getFieldByIndex(int index) const;
    void setFieldByIndex(int index, const std::string &value);
    static std::string getLabelByIndex(int index);
};

#endif