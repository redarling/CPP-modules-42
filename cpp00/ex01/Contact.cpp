#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}

void Contact::setInfo(const std::string& firstName, const std::string& lastName,
                        const std::string& nickname, const std::string& phoneNumber,
                        const std::string& darkestSecret)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickname = nickname;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;
}

void Contact::displayInfo(const std::string& row) const 
{
    if (row.length() > 10)
        std::cout << row.substr(0, 9) << '.' << '|';
    else 
        std::cout << std::setw(10) << row << '|';
}

void Contact::displayShortInfo(int index) const
{
    std::cout << std::setw(10) << index << '|';
    displayInfo(firstName);
    displayInfo(lastName);
    displayInfo(nickname);
    std::cout << std::endl;
}

void Contact::displayFullInfo() const
{
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}