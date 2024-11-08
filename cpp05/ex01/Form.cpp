#include "Form.hpp"

Form::Form() : _name("noname"), _isSigned(false),
        _requiredGradeToSign(1), _requiredGradeToExecute(1) {}

Form::Form(const std::string& name, const int gradeToSign, const int gradeToExecute) :
    _name(name), _isSigned(false),
    _requiredGradeToSign(checkRequiredGrade(gradeToSign)),
    _requiredGradeToExecute(checkRequiredGrade(gradeToExecute)) {}

int                 Form::checkRequiredGrade(int gradeToCheck)
{
    if (gradeToCheck < 1)
        throw (GradeTooHighException());
    else if (gradeToCheck > 150)
        throw (GradeTooLowException());
    return (gradeToCheck);
}

Form::Form(const Form& other) : _name(other.getName()), _isSigned(other.getIsSigned()),
    _requiredGradeToSign(other.getRequiredGradeToSign()),
    _requiredGradeToExecute(other.getRequiredGradeToExecute()) {}

Form::~Form() {}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->_isSigned = other.getIsSigned();
        // other attributes are const
    }
    return (*this);
}

std::string Form::getName() const
{
    return (this->_name);
}

bool        Form::getIsSigned() const
{
    return (this->_isSigned);
}

int         Form::getRequiredGradeToSign() const
{
    return (this->_requiredGradeToSign);
}

int         Form::getRequiredGradeToExecute() const
{
    return (this->_requiredGradeToExecute);
}

void        Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (this->getIsSigned() == true)
        return ;
    if (bureaucrat.getGrade() <= this->getRequiredGradeToSign())
        this->_isSigned = true;
    else
        throw (GradeTooLowException());
}

std::ostream& operator<<(std::ostream &out, const Form &form)
{
    if (form.getIsSigned() == true)
    {
        out << form.getName() << ", Form is signed. Required grade to sign is " 
            << form.getRequiredGradeToSign() << ", Required grade to execute is "
            << form.getRequiredGradeToExecute();
    }
    else
    {
        out << form.getName() << ", Form isn't signed. Required grade to sign is " 
            << form.getRequiredGradeToSign() << ", Required grade to execute is "
            << form.getRequiredGradeToExecute();
    }

    return (out);
}