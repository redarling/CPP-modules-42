#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

int main()
{
    Bureaucrat              bob("Bob", 45);
    Bureaucrat              badWorker("Sorry", 150);

    ShrubberyCreationForm   shrubbery("Garden");
    RobotomyRequestForm     robotomy("Bender");
    PresidentialPardonForm  pardon("Alice");

    /* BAD SIGNS */
    badWorker.signForm(shrubbery);
    badWorker.signForm(robotomy);
    badWorker.signForm(pardon);

    std::cout << std::endl;
    /* GOOD SIGNS */
    bob.signForm(shrubbery);
    bob.executeForm(shrubbery);
    bob.signForm(robotomy);
    bob.executeForm(robotomy);

    std::cout << std::endl;
    /* CHECK SIGN */
    bob.signForm(pardon);
    bob.executeForm(pardon);

    std::cout << std::endl;
    try
    {
        for(int i = 0; i < 45; ++i)
            bob.incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;
    bob.signForm(pardon);
    bob.executeForm(pardon);

    return (0);
}
