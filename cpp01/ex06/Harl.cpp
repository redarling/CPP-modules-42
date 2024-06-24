#include "Harl.hpp"

Harl::Harl() {}

void    Harl::complain(const std::string& level)
{
    static const LevelMap* complaintMap = getComplaintMap();

    for (int i = 0; i < 4; ++i)
    {
        if (level == complaintMap[i].levelName)
        {
            switch (i)
            {
                case 0:
                    (this->*complaintMap[0].function)();
                case 1:
                    (this->*complaintMap[1].function)();
                case 2:
                    (this->*complaintMap[2].function)();
                case 3:
                    (this->*complaintMap[3].function)();
                    return;
            }
        }
    }
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void    Harl::debug(void)
{
    std::cout << "DEBUG: I love having extra bacon"
        << " for my 7XL-double-cheese-triple-pickle-special-ketchup"
        << " burger. I really do!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "INFO: I cannot believe adding"
        << " extra bacon costs more money. You didn't put enough"
        << " bacon in my burger! If you did,"
        << " I wouldn't be asking for more!" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "WARNING: I think I deserve to have"
        << " some extra bacon for free."
        << " I've been coming for years whereas you started" 
        << " working here since last month." << std::endl;
}

void    Harl::error(void)
{
    std::cout << "ERROR: This is unacceptable!"
        << " I want to speak to the manager now." << std::endl;
}

const Harl::LevelMap*   Harl::getComplaintMap(void)
{
    static const LevelMap   complaintMap[4] =
    {
        {"DEBUG", &Harl::debug},
        {"INFO", &Harl::info},
        {"WARNING", &Harl::warning},
        {"ERROR", &Harl::error}
    };
    return (complaintMap);
}
