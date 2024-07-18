#include "ScalarConverter.hpp"
#include <cctype>
#include <climits>

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

// int ScalarConverter::findType(std::string type)
// {
//     char* end;
// 	const char* str = type.c_str();
    
//     double value = strtod(str, &end);
    
// 	if (type.size() == 1)
// 	{
// 		if(isprint(type[0]) && !isdigit(type[0]))
// 		{
// 			std::cout << "char from size(1)" << std::endl;
// 			return 0;
// 		}
// 		else if (isdigit(type[0]))
// 		{
// 			std::cout << "digit from  size(1)" << std::endl; 
// 			return 1;
// 		}
// 	}
// 	else if ((value > INT_MIN && value < INT_MAX) && type.find('.') == type.npos && !end)
// 	{
// 		if (end == str)
// 			throw EmptyError();
// 		if (errno == ERANGE)
// 			throw RangeError();
// 		std::cout << "digit from normal int" << std::endl; 
// 		return 1;
// 	}
// 	else if(type.find('.') != type.npos && end[1] == '\0')
// 	{
// 		if (end == str)
// 			throw EmptyError();
// 		if (errno == ERANGE)
// 			throw RangeError();
// 		if(end[0] == 'f')
// 		{
// 			std::cout << "float" << std::endl;
// 			return 2;
// 		}
// 		else
// 		{
// 			std::cout << "Double" << std::endl;
// 			return 3;
// 		}
// 	}
// 	else
// 		throw InvalidError();
// 	// {
//     //     std::cout << "Converted value: " << value << std::endl;
//     //     std::cout << "Remaining string: " << end << std::endl;
//     // }
// 	// std::cout << std::fixed << std::setprecision(1) << std::endl;
// 	// this is important in fixing if 10.0 is put, as it sets the precision,
// 	// so no need to hardcode the .0 everytime,
// 	return 0;
// }

// bool isValidFloatString(const std::string& str) {
//     std::size_t firstF = str.find('f');
//     std::size_t lastF = str.rfind('f');
//     return (firstF != std::string::npos && firstF == lastF && firstF == str.length() - 1);
// }

int ScalarConverter::findType(const std::string type)
{
    char* end;
    const char* str = type.c_str();
    errno = 0;
    double value = strtod(str, &end);
	if (type.size() == 1)
	{
		if (isprint(type[0]) && !isdigit(type[0]))
            return 0; // char
		else if (isdigit(type[0]))
            return 1; // int digit
    }
	else if ((value >= INT_MIN && value <= INT_MAX) && type.find('.') == std::string::npos && *end == '\0')
	{
        // if (errno == ERANGE)
        //     throw RangeError();

		// Check needed if we want to exit in a cool error message

        return 1; // normal int
    }
	else if (type.find('.') != std::string::npos && (*end == '\0' || (end[0] == 'f' && end[1] == '\0')))
	{
		if (end == str)
            throw EmptyError();
        if (errno == ERANGE)
            throw RangeError();
		if (end[0] == 'f')
            return 2; // float
		else
            return 3; // double
    }
    return -1;
}

void ScalarConverter::convertChar(const std::string& type)
{
    char c = type[0];

    std::cout << "The data type is: Char" << std::endl;
	std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	ScalarConverter::convertInt(const std::string type)
{
	char* end;
    const char* str = type.c_str();
    double value = strtod(str, &end);

	// if(value < INT_MIN || value > INT_MAX)
	// 	throw RangeError();
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "The data type is: Int" << std::endl;
	if (value >= 0 && value <= 255 && isprint(static_cast<int>(value)))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else if (value >= 0 && value <= 255 && !isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "Char: impossible" << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value)  << std::endl;
}

void	ScalarConverter::convertFloat(const std::string type)
{
	char* end;
    const char* str = type.c_str();
    double value = strtod(str, &end);
	
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "The data type is: float" << std::endl;

	std::cout << "char: impossible" << std::endl;
	if (value >= INT_MIN && value <=INT_MAX)
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << value << "f" << std::endl;
    std::cout << "double: " << value << std::endl;
}

void	ScalarConverter::convertDouble(const std::string type)
{
	char* end;
    const char* str = type.c_str();
    double value = strtod(str, &end);
	
		
	std::cout << std::fixed << std::setprecision(1);
	
	std::cout << "The data type is: Double" << std::endl;
	std::cout << "char: impossible" << std::endl;

	if(value >= INT_MIN && value <=INT_MAX)
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << value << std::endl;
}

void ScalarConverter::convert(const std::string type)
{
    int castType = findType(type);

    switch (castType)
	{
		case 0:
			convertChar(type);
			break;
		case 1:
			convertInt(type);
			break;
		case 2:
			convertFloat(type);
			break;
		case 3:
			convertDouble(type);
			break;
		default:
			throw InvalidError();
    }
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
