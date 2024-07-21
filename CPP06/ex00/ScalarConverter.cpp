#include "ScalarConverter.hpp"

/*
====================================== Constructors & Destructor =======================================
*/

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

int ScalarConverter::characterCount(const std::string& str, char ch)
{
    int count = 0;
    for (size_t i = 0; i < str.size(); ++i)
	{
        if (str[i] == ch)
            ++count;
    }
    return count;
}

/*
====================================== Type Checker =======================================
*/

//				char checker
int	ScalarConverter::ifChar(std::string type)
{
	if(type.size() != 1)
		return ERROR;
	if(isprint(type[0]) && !isdigit(type[0]))
		return CHAR;
	else if (isdigit(type[0]))
		return INT;
	return ERROR;
}

//					int checker
int	ScalarConverter::ifInt(std::string type, double value, const char* end)
{
	if((value >= INT_MIN && value <= INT_MAX) && type.find('.') == std::string::npos && *end == '\0')
		return INT;
	return ERROR;
}

//					float & double checker
int	ScalarConverter::ifFloatDouble(std::string type, const char* end)
{
	if(type.find('.') == std::string::npos || characterCount(type, '.') != 1)
		return ERROR;
	if (end[0] == 'f' && strlen(end) == 1)
		return FLOAT;
	else if (end[0] == 'f' && strlen(end) != 1)
		return ERROR;
	return DOUBLE;
}

//					literal checker
int	ScalarConverter::ifLiteral(std::string type)
{
	if (type == "-inff" || type == "+inff" || type == "inff" || type == "nanf")
		return FLITERAL;
	else if (type == "-inf" || type == "+inf" || type == "inf" || type == "nan")
		return DLITERAL;
	return ERROR;
}

// 			find type main function
int ScalarConverter::findType(const std::string type)
{
    char* end;
    const char* str = type.c_str();
    errno = 0;
    double value = strtod(str, &end);

	if (type.empty())
		throw EmptyError();
	if (errno == ERANGE)
		throw RangeError();
	if (ifChar(type)!= ERROR)
		return (ifChar(type));
	else if (ifInt(type, value, end) != ERROR)
        return ifInt(type, value, end);
	else if (ifFloatDouble(type, end) != ERROR)
		return ifFloatDouble(type, end);
	else if (ifLiteral(type) != ERROR)
		return ifLiteral(type);
    return ERROR;
}

/*
====================================== Type Converter =======================================
*/

//					char converter
void ScalarConverter::convertChar(const std::string& type)
{
    char c = type[0];
	std::cout << YELLOW << "The data type is: char" << RESET << std::endl;
	std::cout << GREEN << "char: '" << c << "'" << RESET << std::endl;
    std::cout << BLUE << "int: " << static_cast<int>(c) << RESET <<  std::endl;
    std::cout << MAGENTA << "float: " << static_cast<float>(c) << ".0f" << RESET << std::endl;
    std::cout << RED << "double: " << static_cast<double>(c) << ".0" << RESET << std::endl;
}

//					int converter
void	ScalarConverter::convertInt(const std::string type)
{
	char* end;
    const char* str = type.c_str();
    double value = strtod(str, &end);

	std::cout << YELLOW << "The data type is: Int"  << RESET << std::endl;
	std::cout << std::fixed << std::setprecision(3);
	if (value >= 0 && value <= 255 && isprint(static_cast<int>(value)))
		std::cout << GREEN << "char: '" << static_cast<char>(value) << "'" << RESET << std::endl;
	else if (value >= 0 && value <= 255 && !isprint(static_cast<int>(value)))
		std::cout << GREEN << "char: Non displayable" << RESET << std::endl;
	else
		std::cout << GREEN << "Char: impossible" << RESET << std::endl;
	std::cout << BLUE << "int: " << static_cast<int>(value) << RESET << std::endl;
    std::cout << MAGENTA << "float: " << static_cast<float>(value) << "f" << RESET << std::endl;
    std::cout << RED << "double: " << static_cast<double>(value)  << RESET << std::endl;
}

//					float converter
void	ScalarConverter::convertFloat(const std::string type)
{
	char* end;
    const char* str = type.c_str();
    double value = strtof(str, &end);
	errno = 0;

	if (errno == ERANGE)
		throw RangeError();

	std::cout << std::fixed << std::setprecision(3);
	std::cout << YELLOW << "The data type is: float "  << RESET << std::endl;

	if (value >= 0 && value <= 255 && isprint(static_cast<int>(value)))
		std::cout << GREEN << "char: '" << static_cast<char>(value) << "'" << RESET << std::endl;
	else if (value >= 0 && value <= 255 && !isprint(static_cast<int>(value)))
		std::cout << GREEN << "char: Non displayable" << RESET << std::endl;
	else
		std::cout << GREEN << "Char: impossible" << RESET << std::endl;
	if (value >= INT_MIN && value <=INT_MAX)
		std::cout << BLUE << "int: " << static_cast<int>(value) << RESET << std::endl;
	else
		std::cout << BLUE << "int: impossible" << RESET << std::endl;
    std::cout << MAGENTA << "float: " << static_cast<float>(value) << "f" << RESET << std::endl;
    std::cout << RED << "double: " << static_cast<double>(value) << RESET << std::endl;
}

//					double converter
void	ScalarConverter::convertDouble(const std::string type)
{
	char* end;
    const char* str = type.c_str();
    double value = strtod(str, &end);
	errno = 0;

	if (errno == ERANGE)
		throw RangeError();
	std::cout << YELLOW << "The data type is: Double" << RESET << std::endl;
	if (value >= 0 && value <= 255 && isprint(static_cast<int>(value)))
		std::cout << GREEN << "char: '" << static_cast<char>(value) << "'" << RESET << std::endl;
	else if (value >= 0 && value <= 255 && !isprint(static_cast<int>(value)))
		std::cout << GREEN << "char: Non displayable" << RESET << std::endl;
	else
		std::cout << GREEN << "Char: impossible" << RESET << std::endl;
	std::cout << std::fixed << std::setprecision(3);
	if(value >= INT_MIN && value <=INT_MAX)
		std::cout << BLUE << "int: " << static_cast<int>(value) << RESET << std::endl;
	else
		std::cout << BLUE << "int: impossible" << RESET << std::endl;
    std::cout << MAGENTA << "float: " << static_cast<float>(value) << "f" << RESET << std::endl;
    std::cout << RED << "double: " << static_cast<double>(value) << RESET << std::endl;
}

//				literal float converter
void ScalarConverter::literalFloat(const std::string type)
{
	std::string doubleValue = type.substr(0, type.length() - 1);
	std::cout << YELLOW << "The data type is: float  literal" << RESET << std::endl;
	std::cout << GREEN << "char: impossible" << RESET << std::endl;
	std::cout << BLUE << "int: impossible" << RESET << std::endl;
	std::cout << MAGENTA << "float: " << type << RESET << std::endl;
    std::cout << RED << "double: " << doubleValue << RESET << std::endl;
}

//				literal double converter
void ScalarConverter::literalDouble(const std::string type)
{
	std::cout << YELLOW << "The data type is: double literal" << RESET << std::endl;
	std::cout << GREEN << "char: impossible" << RESET << std::endl;
	std::cout << BLUE << "int: impossible" << RESET << std::endl;
	std::cout << MAGENTA << "float: " << type << "f" << RESET << std::endl;
    std::cout << RED << "double: " << type  << RESET << std::endl;
}

//					Conversion main function
void ScalarConverter::convert(const std::string type)
{
    int castType = findType(type);

    switch (castType)
	{
		case CHAR:
			convertChar(type);
			break;
		case INT:
			convertInt(type);
			break;
		case FLOAT:
			convertFloat(type);
			break;
		case DOUBLE:
			convertDouble(type);
			break;
		case FLITERAL:
			literalFloat(type);
			break;
		case DLITERAL:
			literalDouble(type);
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
