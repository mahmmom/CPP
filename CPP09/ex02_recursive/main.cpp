#include "PmergeMe.hpp"


int main(int argc, char* argv[])
{
    if (argc < 2)
	{
        std::cerr << "Usage: " << argv[0] << " <positive integers>" << std::endl;
        return 1;
    }

    try
	{
    	PmergeMe sorter;
        sorter.parseInput(argc, argv);
        
        std::cout << "Before: " << std::endl;
        sorter.displayResults();

        sorter.sort();

        std::cout << "After: " << std::endl;
        sorter.displayResults();
    }
    catch (std::exception& e)
	{
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}