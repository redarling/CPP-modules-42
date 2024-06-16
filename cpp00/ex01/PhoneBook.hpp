#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    public:
        PhoneBook();
        void addContact();
        void searchContact() const;


    private:
        Contact contacts[8];
        int currentIndex;
        int contactCount;
        std::string getInput(const std::string& prompt);
};

#endif