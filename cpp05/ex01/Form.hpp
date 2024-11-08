#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        Form();
        Form(const std::string& name, const int gradeToSign, const int gradeToExecute);
        Form(const Form& other);
        ~Form();
        Form& operator=(const Form& other);

        std::string         getName() const;
        bool                getIsSigned() const;
        int                 getRequiredGradeToSign() const;
        int                 getRequiredGradeToExecute() const;
        void                beSigned(const Bureaucrat& bureaucrat);
        
        int                 checkRequiredGrade(int gradeToCheck);

    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _requiredGradeToSign;
        const int           _requiredGradeToExecute;
};

std::ostream& operator<<(std::ostream &out, const Form &form);

#endif