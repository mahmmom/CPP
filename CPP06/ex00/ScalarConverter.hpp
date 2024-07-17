#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>  // for strtod
#include <cctype>
#include <climits>
#include <cerrno>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
		static int	findType(std::string type);
	
	public:
		static void convert(std::string type);

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