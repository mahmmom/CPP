#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip>

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

        clock_t start = clock();
        sorter.sort();
        clock_t end = clock();

        std::cout << "After: ";
        sorter.displayResults();

        double time_vector = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
        
        start = clock();
        sorter.sort(); // Sort again to measure list performance
        end = clock();
        
        double time_list = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;

        std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : "
                  << std::fixed << std::setprecision(5) << time_vector << " us" << std::endl;
        std::cout << "Time to process a range of " << argc - 1 << " elements with std::list : "
                  << std::fixed << std::setprecision(5) << time_list << " us" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}