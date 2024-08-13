#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("noname"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) 
    : _name(other.getName()), _grade(other.getGrade()) {}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
    return (this->_name);
}

Bureaucrat&             Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        this->_grade = other.getGrade();
        // _name is const
    }
    return (*this);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade <= 1)
        throw (GradeTooHighException());
    --this->_grade;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade >= 150)
        throw (GradeTooLowException());
    ++this->_grade;
}

void Bureaucrat::signForm(AForm& form)
{
    if (form.getIsSigned() == true)
    {
        std::cout << this->getName() << " couldn’t sign " << form.getName()
                  << " because the form is already signed." << std::endl;
        return;
    }
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->getName() << " couldn’t sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->getName() << " couldn’t executed " << form.getName()
                  << " because " << e.what() << std::endl;
    }  
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return (out);
}
