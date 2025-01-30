#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact();
    void setContact(const std::string& first, const std::string& last, const std::string& nick,
                    const std::string& phone, const std::string& secret);
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    void displayContact() const;
};

#endif