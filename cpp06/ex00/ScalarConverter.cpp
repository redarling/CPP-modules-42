#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return (*this);
}

LiteralType ScalarConverter::getType(const std::string& input)
{
    if (input.empty())
        return (UNKNOWN);

    if (input == "nan" || input == "nanf" || input == "+inf" || \
        input == "-inf" || input == "+inff" || \
        input == "-inff" || input == "inf" || input == "inff")
    {
        return (SPECIAL);
    }

    if (input.length() == 1 && !std::isdigit(input[0]))
        return (CHAR);

    std::string::size_type i = (input[0] == '-' || input[0] == '+') ? 1 : 0;
    bool hasDot = false;

    while (i < input.length() && std::isdigit(input[i]))
        i++;

    if (i < input.length() && input[i] == '.' && std::isdigit(input[i - 1]))
    {
        hasDot = true;
        i++;
        while (i < input.length() && std::isdigit(input[i]))
            i++;
    }

    if (i < input.length() && input[i] == 'f' && hasDot)
        return ((i + 1 == input.length()) ? FLOAT : UNKNOWN);

    if (i == input.length())
        return (hasDot ? DOUBLE : INT);

    return (UNKNOWN);
}

void    ScalarConverter::printChar(const char charValue)
{
    if (std::isprint(charValue))
        std::cout << "char: '" << charValue << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void    ScalarConverter::printInt(const long longValue)
{
    if (longValue > std::numeric_limits<int>::max() || \
            longValue < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(longValue) << std::endl;
}

void    ScalarConverter::fromChar(const std::string& input)
{
    char    CharValue = input[0];

    printChar(CharValue);
    
    std::cout << "int: " << static_cast<int>(CharValue) << std::endl;
    
    std::cout << "float: "  << std::fixed << std::setprecision(1) 
              << static_cast<float>(CharValue)  << "f" << std::endl;
    
    std::cout << "double: " << std::fixed << std::setprecision(1) 
              << static_cast<double>(CharValue) << std::endl;
}

void    ScalarConverter::fromInt(const std::string& input)
{
    long    longValue = std::strtol(input.c_str(), NULL, 10);
    char    charValue = static_cast<char>(longValue);
    double  doubleValue = std::strtod(input.c_str(), NULL);

    if (longValue < 0 || longValue > 255)
        std::cout << "char: impossible" << std::endl;
    else
        printChar(charValue);
    
    printInt(longValue);

    std::cout << "float: "  << std::fixed << std::setprecision(1) 
              << static_cast<float>(doubleValue)  << "f" << std::endl;
    
    std::cout << "double: " << std::fixed << std::setprecision(1) 
              << doubleValue << std::endl;
}

void    ScalarConverter::fromFloatOrDouble(const std::string& input)
{
    double  doubleValue = std::strtod(input.c_str(), NULL);
    char    charValue = static_cast<char>(doubleValue);

    if ((doubleValue < 0.0 || doubleValue > 255.0))
        std::cout << "char: impossible" << std::endl;
    else
        printChar(charValue);
    
    printInt(static_cast<long>(doubleValue));

    std::cout << "float: "  << std::fixed << std::setprecision(1) 
              << static_cast<float>(doubleValue)  << "f" << std::endl;

    std::cout << "double: " << std::fixed << std::setprecision(1) 
              << doubleValue << std::endl;
}

void    ScalarConverter::fromSpecial(const std::string& input)
{
    if (input == "nan" || input == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (input == "+inf" || input == "+inff" || input == "inf" || input == "inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (input == "-inf" || input == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void    ScalarConverter::convert(const std::string& input)
{
    LiteralType type = getType(input);

    switch (type)
    {
        case SPECIAL:
            fromSpecial(input);
            break;
        case CHAR:
            fromChar(input);
            break;
        case INT:
            fromInt(input);
            break;
        case FLOAT:
            fromFloatOrDouble(input);
            break;
        case DOUBLE:
            fromFloatOrDouble(input);
            break;
        default:
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            break;
    }
}