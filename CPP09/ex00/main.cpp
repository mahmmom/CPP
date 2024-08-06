#include "BitcoinExchange.hpp"


int main(int ac, char** av)
{
	if (ac == 2)
	{
		try
		{
			std::string file = av[1];
			BitcoinExchange exchange;
			exchange.fillData(file);
			exchange.printMap();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
	{
		std::cerr << "Error: Wrong input" << std::endl;
		std::cerr << "Enter: ./btc <file>" << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
