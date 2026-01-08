//
// Created by tjooris on 12/10/25.
//

#include "ScalarConverter.hpp"
#include <sstream>
#include <climits>

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter(){}

static bool isChar(const std::string &literal)
{
    return literal.length() == 1 && !std::isdigit(literal[0]);
}

static bool isInt(const std::string &literal)
{
    size_t i = 0;
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    for (; i < literal.length(); i++)
    {
        if (!std::isdigit(literal[i]))
            return false;
    }
    return true;
}

static bool isFloat(const std::string &literal)
{
    size_t i = 0;
    bool hasDecimal = false;
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    for (; i < literal.length(); i++)
    {
        if (literal[i] == '.')
        {
            if (hasDecimal)
                return false;
            hasDecimal = true;
        }
        else if (!std::isdigit(literal[i]) && literal[i] != 'f')
        {
            return false;
        }
    }
    return hasDecimal && literal[literal.length() - 1] == 'f';
}

static bool isDouble(const std::string &literal)
{
    size_t i = 0;
    bool hasDecimal = false;
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    for (; i < literal.length(); i++)
    {
        if (literal[i] == '.')
        {
            if (hasDecimal)
                return false;
            hasDecimal = true;
        }
        else if (!std::isdigit(literal[i]))
        {
            return false;
        }
    }
    return hasDecimal;
}

static bool isSpecial(const std::string &literal)
{
    return literal == "nan" || literal == "+inf" || literal == "-inf" ||
           literal == "nanf" || literal == "+inff" || literal == "-inff";
}

void ScalarConverter::convert(const std::string &literal)
{
    if (isChar(literal))
    {
        char c = literal[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
    }
    else if (isInt(literal))
    {
        std::stringstream ss(literal);
        int i;
        ss >> i;

        if (i >= 32 && i <= 126)
            std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << std::endl;
    }
    else if (isFloat(literal))
    {
        float f = static_cast<float>(std::atof(literal.c_str()));

        if (f >= 32 && f <= 126 && f == static_cast<int>(f))
            std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        if (f >= static_cast<float>(INT_MIN) && f <= static_cast<float>(INT_MAX))
            std::cout << "int: " << static_cast<int>(f) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    }
    else if (isDouble(literal))
    {
        double d = std::atof(literal.c_str());

        if (d >= 32 && d <= 126 && d == static_cast<int>(d))
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        if (d >= INT_MIN && d <= INT_MAX)
            std::cout << "int: " << static_cast<int>(d) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
    else if (isSpecial(literal))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        if (literal == "nan" || literal == "nanf")
        {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else if (literal == "+inf" || literal == "+inff")
        {
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
        else if (literal == "-inf" || literal == "-inff")
        {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}