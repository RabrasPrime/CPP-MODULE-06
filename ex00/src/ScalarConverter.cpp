//
// Created by tjooris on 12/10/25.
//

#include "ScalarConverter.hpp"
#include <sstream>
#include <limits>
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
    if (literal.empty())
        return false;

    size_t i = 0;
    if (literal[i] == '-' || literal[i] == '+')
        i++;

    if (i >= literal.length())
        return false;

    for (; i < literal.length(); i++)
    {
        if (!std::isdigit(literal[i]))
            return false;
    }

    std::stringstream ss(literal);
    long value;
    ss >> value;

    if (ss.fail() || !ss.eof() || value > std::numeric_limits<int>::max()
        || value < std::numeric_limits<int>::min())
        return false;

    return true;
}

static bool isFloat(const std::string &literal)
{
    if (literal.empty() || literal[literal.length() - 1] != 'f')
        return false;

    size_t i = 0;
    bool hasDecimal = false;
    if (literal[i] == '-' || literal[i] == '+')
        i++;

    for (; i < literal.length() - 1; i++)
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

static bool isDouble(const std::string &literal)
{
    if (literal.empty())
        return false;

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
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
    }
    else if (isInt(literal))
    {
        std::stringstream ss(literal);
        long temp;
        ss >> temp;
        int i = static_cast<int>(temp);

        if (i >= 32 && i <= 126)
            std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
        else if (i >= 0 && i <= 127)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;

        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
    }
    else if (isFloat(literal))
    {
        std::stringstream ss(literal);
        float f;
        ss >> f;

        if (std::isnan(f) || std::isinf(f))
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
        }
        else
        {
            if (f >= 32.0f && f <= 126.0f && f == static_cast<int>(f))
                std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
            else if (f >= 0.0f && f <= 127.0f && f == static_cast<int>(f))
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char: impossible" << std::endl;

            if (f > static_cast<float>(std::numeric_limits<int>::max()) ||
                f < static_cast<float>(std::numeric_limits<int>::min()))
                std::cout << "int: impossible" << std::endl;
            else
                std::cout << "int: " << static_cast<int>(f) << std::endl;
        }

        if (f == static_cast<int>(f) && !std::isnan(f) && !std::isinf(f))
            std::cout << "float: " << f << ".0f" << std::endl;
        else
            std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    }
    else if (isDouble(literal))
    {
        std::stringstream ss(literal);
        double d;
        ss >> d;

        if (std::isnan(d) || std::isinf(d))
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
        }
        else
        {
            if (d >= 32.0 && d <= 126.0 && d == static_cast<int>(d))
                std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
            else if (d >= 0.0 && d <= 127.0 && d == static_cast<int>(d))
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char: impossible" << std::endl;

            if (d > static_cast<double>(std::numeric_limits<int>::max()) ||
                d < static_cast<double>(std::numeric_limits<int>::min()))
                std::cout << "int: impossible" << std::endl;
            else
                std::cout << "int: " << static_cast<int>(d) << std::endl;
        }

        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        if (d == static_cast<int>(d) && !std::isnan(d) && !std::isinf(d))
            std::cout << "double: " << d << ".0" << std::endl;
        else
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