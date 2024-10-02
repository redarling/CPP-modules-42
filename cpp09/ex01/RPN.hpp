#include <stack>
#include <iostream>

class RPN
{
    private:
        std::stack<int> _stack;

        bool    parse(const std::string& str);

    public:
        RPN();
        RPN(const RPN& other);
        ~RPN();
        RPN&    operator=(const RPN& other);

        void    calculate(const std::string& str);
};