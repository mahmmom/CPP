#include "Span.hpp"
#include <exception>
#include <vector>

int main()
{
    try
	{
		Span sp = Span(5);
    // Span random = Span(5);
		sp.addNumber(-6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(-11);

		// random.addRandomNumbers(5);
		// std::cout << "Span contents: {";
		// for (std::size_t i = 0; i < random.getSize(); ++i)
		// {
		//     std::cout << random.getVector()[i] << " ";
		// }
		// std::cout << "}" << std::endl;

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
    
    return 0;
}