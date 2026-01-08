//
// Created by tjooris on 12/10/25.
//

#ifndef CPP_MODULE_06_SCALARCONVERTER_HPP
#define CPP_MODULE_06_SCALARCONVERTER_HPP
#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <cerrno>
#include <cmath>

class ScalarConverter
{
	public:
		static void	convert(const std::string &literal);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

};


#endif //CPP_MODULE_06_SCALARCONVERTER_HPP