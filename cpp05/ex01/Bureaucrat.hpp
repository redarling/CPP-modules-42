#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "GradeTooHighException.hpp"
# include "GradeTooLowException.hpp"
# include "Form.hpp"

class Form;

class Bureaucrat
{
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat();
        Bureaucrat&             operator=(const Bureaucrat& other);
        

        std::string         getName() const;
        int                 getGrade() const;

        void                incrementGrade();
        void                decrementGrade();

        void                signForm(Form& form);

    private:
        const std::string   _name;
        int                 _grade;
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif