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
    int         error_flag;
public:
    Contact();
    std::string        getFieldByIndex(int index) const;
    void               setFieldByIndex(int index, const std::string &value);
    static std::string getLabelByIndex(int index);
    int                getErrorFlag() const;
};

#endif