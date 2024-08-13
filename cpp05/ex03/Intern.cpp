#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return (*this);
}

AForm* Intern::createShrubberyCreationForm(const std::string& target) const
{
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) const
{
    return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) const
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    static const FormMap* formMap = getFormMap();

    for (int i = 0; i < 3; ++i)
    {
        if (formName == formMap[i].formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*(formMap[i].function))(target);
        }
    }

    std::cout << "Intern can't create this form: " << formName << std::endl;
    return (nullptr);
}

const Intern::FormMap*   Intern::getFormMap(void)
{
    static const FormMap   Map[3] =
    {
        {"shrubbery creation", &Intern::createShrubberyCreationForm},
        {"robotomy request", &Intern::createRobotomyRequestForm},
        {"presidential pardon", &Intern::createPresidentialPardonForm}
    };
    return (Map);
}