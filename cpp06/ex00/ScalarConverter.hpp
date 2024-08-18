#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cctype>
# include <limits>
# include <iomanip>

enum LiteralType { CHAR, INT, FLOAT, DOUBLE, SPECIAL, UNKNOWN };

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ~ScalarConverter();
        ScalarConverter&    operator=(const ScalarConverter& other);

        static LiteralType  getType(const std::string& input);

        static void         printChar(const char charValue);
        static void         printInt(const long longValue);

        static void         fromChar(const std::string& input);
        static void         fromInt(const std::string& input);
        static void         fromFloatOrDouble(const std::string& input);
        static void         fromSpecial(const std::string& input);

    public:
        static void         convert(const std::string& input);
};

#endif
