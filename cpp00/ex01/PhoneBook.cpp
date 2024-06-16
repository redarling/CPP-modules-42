#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : currentIndex(0), contactCount(0) {}

std::string PhoneBook::getInput(const std::string& prompt)
{
    std::string input;

    while (true)
    {
        if (std::cin.eof())
            break;
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        if (!input.empty())
            break;
        std::cout << "Error: Input cannot be empty." << std::endl;
    }
    return (input);
}

void PhoneBook::addContact()
{
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    firstName = getInput("Enter First Name: ");
    lastName = getInput("Enter Last Name: ");
    nickname = getInput("Enter Nickname: ");
    phoneNumber = getInput("Enter Phone Number: ");
    darkestSecret = getInput("Enter Darkest Secret: ");

    contacts[currentIndex].setInfo(firstName, lastName, nickname,
                                    phoneNumber, darkestSecret);
    currentIndex = (currentIndex + 1) % 8;
    if (contactCount < 8)
        contactCount++;
}

void PhoneBook::searchContact() const
{
    int index;

    std::cout << std::setw(10) << "Index" << '|';
    std::cout << std::setw(10) << "First Name" << '|';
    std::cout << std::setw(10) << "Last Name" << '|';
    std::cout << std::setw(10) << "Nickname" << '|';
    std::cout << std::setw(10) << "Phone Num" << '|';
    std::cout << std::setw(10) << "D. Secret" << '|' << std::endl;

    for (int i = 0; i < contactCount; i++)
        contacts[i].displayShortInfo(i);

    std::cout << "Enter the index of the contact to display: ";
    std::cin >> index;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Invalid index. Input was not a number." << std::endl;
        return ;
    }
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (index < 0 || index >= contactCount)
        std::cout << "Error: Invalid index." << std::endl;
    else
        contacts[index].displayFullInfo();
}
