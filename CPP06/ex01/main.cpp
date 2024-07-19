#include "ScalarConverter.hpp"









int main(int ac, char** av)
{
	if(ac != 2)
		return(std::cerr << "Invalid Arguemnt, Enter ./convert <string>" << std::endl, 1);
	try
	{
		ScalarConverter::convert(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
