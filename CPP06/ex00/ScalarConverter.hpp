#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>  // for strtod
#include <cctype>
#include <climits>
#include <cerrno>
#include <iomanip>

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