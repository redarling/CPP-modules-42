#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include "Bureaucrat.hpp"
# include "NotSignedException.hpp"

class Bureaucrat;

class AForm
{
    public:
        AForm();
        AForm(const std::string& name, const int gradeToSign, const int gradeToExecute);
        AForm(const AForm& other);
        virtual             ~AForm();
        AForm&              operator=(const AForm& other);

        std::string         getName() const;
        bool                getIsSigned() const;
        int                 getRequiredGradeToSign() const;
        int                 getRequiredGradeToExecute() const;
        void                beSigned(const Bureaucrat& bureaucrat);
        void                execute(const Bureaucrat& executor) const;
        int                 checkRequiredGrade(int gradeToCheck);

    private:
        virtual void        performAction() const = 0;
        const std::string   _name;
        bool                _isSigned;
        const int           _requiredGradeToSign;
        const int           _requiredGradeToExecute;
};

std::ostream& operator<<(std::ostream &out, const AForm &form);

#endif