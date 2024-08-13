#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("undefined")
{
    std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target)
{
    std::srand(std::time(0));
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&  RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return (*this);
}

void RobotomyRequestForm::performAction() const
{
    std::cout << "drrrrrrrrrrrrrrrr......." << std::endl;

    int success = std::rand() % 2;

    if (success)
    {
        std::cout << this->_target
                  << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "The robotomy of "
                  << this->_target << " failed!" << std::endl;
    }
}
