#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "Default ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
	std::cout << "Copy ScalarConverter constructor called" << std::endl; // nothing to copy
	if (this != &copy)
		*this = copy;
	*this = copy;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &copy)
{
	std::cout << "Scalar converter assignment operator called" << std::endl;
	if (this != &copy)
		return *this;
	return *this;
}

static bool isNumeric(const std::string &src)
{
	char* end = NULL;
	std::strtod(src.c_str(), &end);
    return *end == '\0';
}

bool isInteger(double num)
{
	double intPart;
	double fracPart = std::modf(num, &intPart);
	return fracPart == 0.0;
}

static bool isSpecialFloat(const std::string &src)
{
	return src == "+inff" || src == "-inff" || src == "nanf";
}

static bool isSpecialDouble(const std::string &src)
{
	return src == "+inf" || src == "-inf" || src == "nan";
}

void ScalarConverter::convertChar(std::string const &src)
{
	if (src.length() == 3 && src[0] == '\'' && src[2] == '\'')
	{
		char val = src[1];
		if (isprint(val))
			std::cout << "char: " << val << std::endl;
		else
			std::cout << "char: not displayable" << std::endl;
	}
	else
	{
		std::string srcCopy = src;
		if (srcCopy[srcCopy.length() - 1] == 'f')
		{
        	srcCopy[srcCopy.length() - 1] = '\0';
		}
		if (isNumeric(srcCopy) && !isSpecialFloat(src) && !isSpecialDouble(src))
		{
       		long intVal = std::strtol(src.c_str(), NULL, 10);
			if (isprint((char)intVal))
				std::cout << "char: '" << (char)intVal  << "'" << std::endl;
			else
				std::cout << "char: not displayable" << std::endl;
    	}
		else
        	std::cout << "char: impossible" << std::endl;
	}
}

void ScalarConverter::convertInt(std::string const &src)
{
	std::string srcCopy = src;
    if (srcCopy[srcCopy.length() - 1] == 'f')
	{	srcCopy[srcCopy.length() - 1] = '\0';}
	if (isNumeric(srcCopy) && !isSpecialFloat(src) && !isSpecialDouble(src))
	{
        long intVal = std::strtol(src.c_str(), NULL, 10);
		if (intVal >= std::numeric_limits<int>::min() && intVal <= std::numeric_limits<int>::max())
			std::cout << "int: " << intVal << std::endl;
		else
			std::cout << "int: out of range" << std::endl;
    }
	else
        std::cout << "int: impossible" << std::endl;
}

void ScalarConverter::convertFloat(std::string const &src)
{
	if (isSpecialFloat(src))
		std::cout << "float: " << src << std::endl;
	else
	{
		if (isSpecialDouble(src))
		{
			std::cout << "float: " << src << "f" << std::endl;
			return ;
		}
		std::string srcCopy = src;
        if (srcCopy[srcCopy.length() - 1] == 'f')
            srcCopy[srcCopy.length() - 1] = '\0';
		if (isNumeric(srcCopy))
		{
            float floatValue = std::strtof(srcCopy.c_str(), NULL);
            std::cout << "float: " << floatValue;
			if (isInteger(floatValue) && floatValue != INFINITY)
				std::cout << ".0";
			std::cout << "f" << std::endl;
        }
		else
        	std::cout << "float: impossible" << std::endl;
	}
}

void ScalarConverter::convertDouble(std::string const &src)
{
	if (isSpecialDouble(src))
		std::cout << "double: " << src << std::endl;
	else
	{
		std::string srcCopy = src;
        if (srcCopy[srcCopy.length() - 1] == 'f')
            srcCopy[srcCopy.length() - 1] = '\0';
		if (isNumeric(srcCopy))
		{
            double doubleValue = std::strtod(srcCopy.c_str(), NULL);
            std::cout << "double: " << doubleValue;
			if (isInteger(doubleValue) && doubleValue != INFINITY)
				std::cout << ".0";
			std::cout << std::endl;
        }
		else
        	std::cout << "double: impossible" << std::endl;
	}
}

void ScalarConverter::convert(const std::string &src)
{
	convertChar(src);
	convertInt(src);
	convertFloat(src);
	convertDouble(src);
}
