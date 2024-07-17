#include "ScalarConverter.hpp"
#include <iomanip>

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	std::cout << "ScalarConverter copy assignment operator called" << std::endl;
	if(this != &other) {}
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

int ScalarConverter::findType(std::string type)
{
    char* end;
	const char* str = type.c_str();
    
    double value = strtod(str, &end);
    
	if (type.size() == 1)
	{
		if(isprint(type[0]) && !isdigit(type[0]))
		{
			std::cout << "char from size(1)" << std::endl;
			return 0;
		}
		else if (isdigit(type[0]))
		{
			std::cout << "digit from  size(1)" << std::endl; 
			return 1;
		}
	}
	else if ((value > INT_MIN && value < INT_MAX) && type.find('.') == type.npos)
	{
		if (end == str)
			throw EmptyError();
		if (errno == ERANGE)
			throw RangeError();
		std::cout << "digit from normal int" << std::endl; 
		return 1;
	}
	else
		throw InvalidError();
	// {
    //     std::cout << "Converted value: " << value << std::endl;
    //     std::cout << "Remaining string: " << end << std::endl;
    // }
	std::cout << std::fixed << std::setprecision(1) << std::endl;
	// this is important in fixing if 10.0 is put, as it sets the precision,
	// so no need to hardcode the .0 everytime,
	return 0;
}

void ScalarConverter::convert(std::string type)
{
	int castType = findType(type);
	(void)castType;
	// switch (expression)
	// {
	// case /* constant-expression */:
	// 	/* code */
	// 	break;
	
	// default:
	// 	break;
	// }
}


/*
====================================== Exceptions =======================================
*/

const char* ScalarConverter::RangeError::what() const throw()
{
	return "Numerical result out of range";
}

const char* ScalarConverter::InvalidError::what() const throw()
{
	return "Invalid value";
}

const char* ScalarConverter::EmptyError::what() const throw()
{
	return "Empty string entered";
}
