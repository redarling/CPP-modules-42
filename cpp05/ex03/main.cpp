#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern      someRandomIntern;
    AForm*      shcf;
    AForm*      rrf;
    AForm*      prf;
    AForm*      invalidForm;
    Bureaucrat  bob("Bob", 1);
    
    shcf = someRandomIntern.makeForm("shrubbery creation", "home");
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    prf = someRandomIntern.makeForm("presidential pardon", "Rocky");
    invalidForm = someRandomIntern.makeForm("lol", "Iron Man");
    
    std::cout << std::endl;
    if (shcf)
    {
        try
        {
            shcf->beSigned(bob);
            shcf->execute(bob);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        delete (shcf);
    }
    else
        std::cout << "This form isn't exist! Sorry..." << std::endl;

    std::cout << std::endl;
    if (rrf)
    {
        try
        {
            rrf->beSigned(bob);
            rrf->execute(bob);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        delete (rrf);
    }
    else
        std::cout << "This form isn't exist! Sorry..." << std::endl;

    std::cout << std::endl;
    if (prf)
    {
        try
        {
            prf->beSigned(bob);
            prf->execute(bob);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        delete (prf);
    }
    else
        std::cout << "This form isn't exist! Sorry..." << std::endl;

    std::cout << std::endl;
    if (invalidForm)
    {
        try
        {
            invalidForm->beSigned(bob);
            invalidForm->execute(bob);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        delete (invalidForm);
    }

    return (0);
}
