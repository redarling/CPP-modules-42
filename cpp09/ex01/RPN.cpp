#include "RPN.hpp"

RPN::RPN() :_stack() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
    {
        this->_stack = other._stack;
    }
    return (*this);
}

bool    RPN::parse(const std::string& str)
{
    int num_count = 0;
    int token_count = 0;

    for (size_t i = 0; i < str.size(); ++i)
    {
        if (str[i] == ' ')
            continue ;
        else if ((i == 0 || (i > 0 && str[i - 1] == ' ')) && std::isdigit(str[i]))
        {
            num_count++;
            continue ;
        }
        else if ((i == 0 || (i > 0 && str[i - 1] == ' ')) && 
            (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*'))
        {
            token_count++;
            continue ;
        }
        else
        {
            std::cerr << "Error: Your string doesn't respect the rules" << std::endl;
            return (false);
        }
    }
    if (num_count != token_count + 1)
    {
        std::cerr << "Error: Bad ratio number / token" << std::endl;
        return (false);
    }
    return (true);
}

void    RPN::calculate(const std::string& str)
{
    long    num;

    if (!parse(str))
        return ;

    for (size_t i = 0; i < str.size(); ++i)
    {
        if (std::isdigit(str[i]))
        {
            this->_stack.push(str[i] - '0');
            continue ;
        }
        else if (this->_stack.size() == 0 && !std::isdigit(str[i]))
        {
            std::cerr << "Error: Your string doesn't respect the rules" << std::endl;
            return ;
        }
        
        if (str[i] == ' ')
            continue ;

        num = this->_stack.top();
        
        if (this->_stack.size() < 2)
        {
            std::cerr << "Error: Your string doesn't respect the rules" << std::endl;
            return ;
        }
        
        this->_stack.pop();

        if (str[i] == '+')
            num = this->_stack.top() + num;
        else if (str[i] == '-')
            num = this->_stack.top() - num;
        else if (str[i] == '/')
        {
            if (num == 0)
            {
                std::cerr << "Error: Division by 0" << std::endl;
                return ;
            }
            num = this->_stack.top() / num;
        }
        else if (str[i] == '*')
            num = this->_stack.top() * num;
        
        this->_stack.pop();
        this->_stack.push(num);
    }

    if (this->_stack.empty())
    {
        std::cerr << "Error: Stack is empty, no result available" << std::endl;
        return ;
    }

    std::cout << this->_stack.top() << std::endl;
}