#include "Span.hpp"
#include <exception>
#include <vector>

int main()
{
    try
	{
		std::cout << YELLOW << "============" << std::endl
		<< "Normal entry" << std::endl
		<< "============" << RESET << std::endl;
		Span sp = Span(10000);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << BLUE << "Span contents: {";
		for (std::size_t i = 0; i < sp.getVector().size(); i++)
		{
		    std::cout << sp.getVector()[i] << " ";
		}
		std::cout << "}" << std::endl;
		
		sp.addRandomNumbers(10);
		std::cout << GREEN << "Random Numbers contents: {";
		for (std::size_t i = 0; i < sp.getVector().size(); i++)
		{
		    std::cout << sp.getVector()[i] << " ";
		}
		std::cout << "}" << std::endl;
		std::cout << MAGENTA << sp.shortestSpan() << std::endl;
		std::cout << MAGENTA << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << RED << "Exception thrown: " << e.what() << RESET << std::endl;
	}
    
    return 0;
}
