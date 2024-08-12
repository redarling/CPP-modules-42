#include "AForm.hpp"

AForm::AForm() : _name("noname"), _isSigned(false),
        _requiredGradeToSign(1), _requiredGradeToExecute(1) {}

AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExecute) :
    _name(name), _isSigned(false),
    _requiredGradeToSign(checkRequiredGrade(gradeToSign)),
    _requiredGradeToExecute(checkRequiredGrade(gradeToExecute)) {}

int                 AForm::checkRequiredGrade(int gradeToCheck)
{
    if (gradeToCheck < 1)
        throw (GradeTooHighException());
    else if (gradeToCheck > 150)
        throw (GradeTooLowException());
    return (gradeToCheck);
}

AForm::AForm(const AForm& other) : _name(other.getName()), _isSigned(other.getIsSigned()),
    _requiredGradeToSign(other.getRequiredGradeToSign()),
    _requiredGradeToExecute(other.getRequiredGradeToExecute()) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        this->_isSigned = other.getIsSigned();
    }
    return (*this);
}

std::string AForm::getName() const
{
    return (this->_name);
}

bool        AForm::getIsSigned() const
{
    return (this->_isSigned);
}

int         AForm::getRequiredGradeToSign() const
{
    return (this->_requiredGradeToSign);
}

int         AForm::getRequiredGradeToExecute() const
{
    return (this->_requiredGradeToExecute);
}

void    AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (this->getIsSigned() == true)
        return ;
    if (bureaucrat.getGrade() <= this->getRequiredGradeToSign())
        this->_isSigned = true;
    else
        throw (GradeTooLowException());
}

void    AForm::execute(const Bureaucrat &executor) const
{
    if (this->getIsSigned() == false)
        throw (NotSignedException());
    if (executor.getGrade() > this->getRequiredGradeToExecute())
        throw (GradeTooLowException());
    this->performAction();
}

std::ostream& operator<<(std::ostream &out, const AForm &form)
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