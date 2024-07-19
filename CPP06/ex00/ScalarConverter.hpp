#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <cerrno>
#include <cstring>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"



enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	FLITERAL,
	DLITERAL,
	ERROR,
};


class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
		static int	findType(const std::string type);
		static void	convertChar(const std::string& type);
		static void	convertInt(const std::string type);
		static void	convertFloat(const std::string type);
		static void	convertDouble(const std::string type);
		static void	literalFloat(const std::string type);
		static void	literalDouble(const std::string type);
		static int	characterCount(const std::string& str, char ch);
		static int	ifChar(std::string type);
		static int	ifInt(std::string type, double value, const char* end);
		static int	ifFloatDouble(std::string type, const char* end);
		static int	ifLiteral(std::string type);
	
	public:
		static void convert(const std::string type);

	class RangeError : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class InvalidError : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class EmptyError : public std::exception
	{
		public:
			const char* what() const throw();
	};
};


#endif