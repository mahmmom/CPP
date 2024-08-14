#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cerr << "Error: Please provide a sequence of positive integers." << std::endl;
        return 1;
    }

    PmergeMe sorter;

    try
	{
        sorter.parseInput(argc, argv);
        std::cout << "Before: ";
        sorter.displayResults();
        sorter.sort();
        std::cout << "After: ";
        sorter.displayResults();
    }
	catch (const std::exception& e)
	{
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}