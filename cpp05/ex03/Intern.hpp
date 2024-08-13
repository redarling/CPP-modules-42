#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern& other);
        ~Intern();
        Intern& operator=(const Intern& other);

        AForm*  makeForm(const std::string& formName, const std::string& target);

    private:
        AForm*  createShrubberyCreationForm(const std::string& target) const;
        AForm*  createRobotomyRequestForm(const std::string& target) const;
        AForm*  createPresidentialPardonForm(const std::string& target) const;

        typedef AForm* (Intern::*FormMemFn)(const std::string& target) const;
        struct FormMap
        {
            const std::string   formName;
            FormMemFn           function;
        };
        
        static const FormMap*   getFormMap(void);
};

#endif