#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        virtual                 ~RobotomyRequestForm();
        RobotomyRequestForm&    operator=(const RobotomyRequestForm& other);

    private:
        virtual void            performAction() const;
        std::string             _target;
    
};

#endif