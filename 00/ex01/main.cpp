#include "PhoneBook.hpp"
#include <iostream>
#include <string>

std::string getInput(const std::string& prompt)
{
    std::string input;
    do
    {
        std::cout << prompt;
        std::getline(std::cin, input);
    }
    while (input.empty());
    return input;
}

int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, or EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD")
        {
            Contact newContact;
            std::string firstName = getInput("Enter first name: ");
            std::string lastName = getInput("Enter last name: ");
            std::string nickname = getInput("Enter nickname: ");
            std::string phoneNumber = getInput("Enter phone number: ");
            std::string darkestSecret = getInput("Enter darkest secret: ");

            newContact.setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
            phoneBook.addContact(newContact);
            std::cout << "Contact added successfully." << std::endl;
        }
        else if (command == "SEARCH")
        {
            phoneBook.searchContact();
        }
        else if (command == "EXIT")
        {
            break;
        }
        else
        {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }

    return 0;
}