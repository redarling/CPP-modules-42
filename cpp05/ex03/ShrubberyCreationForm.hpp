#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        virtual                 ~ShrubberyCreationForm();
        ShrubberyCreationForm&  operator=(const ShrubberyCreationForm& other);

    private:
        virtual void            performAction() const;
        std::string             _target;
};

#endif