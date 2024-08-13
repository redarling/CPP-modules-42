#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("undefined") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return (*this);
}

void ShrubberyCreationForm::performAction() const
{
    std::ofstream   outputFile(this->_target + "_shrubbery");
    
    if (!outputFile)
    {
        std::cerr << "Unable to open file for writing!" << std::endl;
        return ;
    }
    
    outputFile << "   *\n  ***\n *****\n*******\n   |\n";
    outputFile.close();
}
