#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

int main()
{
    Bureaucrat              bob("Bob", 45);
    ShrubberyCreationForm   shrubbery("Garden");
    RobotomyRequestForm     robotomy("Bender");
    PresidentialPardonForm  pardon("Alice");

    bob.signForm(shrubbery);
    bob.executeForm(shrubbery);

    bob.signForm(robotomy);
    bob.executeForm(robotomy);

    bob.signForm(pardon);
    bob.executeForm(pardon);

    return 0;
}
