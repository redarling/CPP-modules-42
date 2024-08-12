#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        virtual                 ~PresidentialPardonForm();
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

    private:
        virtual void            performAction() const;
        std::string             _target;
    
};

#endif