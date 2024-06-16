#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
    public:
        Contact();
        void setInfo(const std::string& firstName, const std::string& lastName,
                        const std::string& nickname, const std::string& phoneNumber, 
                            const std::string& darkestSecret);
        void displayShortInfo(int index) const;
        void displayFullInfo() const;

    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
        void displayInfo(const std::string& prompt) const ;
};

#endif
