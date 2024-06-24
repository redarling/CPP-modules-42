#include <iostream>
#include "PhoneBook.hpp"

int main(void)
{
    std::string cmd;
    PhoneBook phoneBook;

    std::cout << "Welcome to the PhoneBook!" << std::endl << std::endl;
    while (true)
    {
        if (std::cin.eof())
            break;
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, cmd))
            break;
        if (cmd == "ADD")
            phoneBook.addContact();
        else if (cmd == "SEARCH")
            phoneBook.searchContact();
        else if (cmd == "EXIT")
            break ;
        else 
            std::cout << "Invalid command!" << std::endl;
    }
    return (0);
}