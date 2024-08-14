#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(int argc, char* argv[])
{
    for (int i = 1; i < argc; ++i)
	{
        int num = std::atoi(argv[i]);
        if (num <= 0)
            throw std::invalid_argument("Error: Invalid input. Only positive integers are allowed.");
        vec.push_back(num);
        deq.push_back(num);
    }
}

void PmergeMe::sort()
{
    sortVector();
    sortDeque();
}

void PmergeMe::sortVector()
{
    clock_t start = clock();
    mergeInsertSort(vec.begin(), vec.end());
    clock_t end = clock();
    double time_taken = double(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " 
              << time_taken << " us" << std::endl;
}

void PmergeMe::sortDeque()
{
    clock_t start = clock();
    mergeInsertSort(deq.begin(), deq.end());
    clock_t end = clock();
    double time_taken = double(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " 
              << time_taken << " us" << std::endl;
}

template<typename Iterator>
void PmergeMe::mergeInsertSort(Iterator begin, Iterator end)
{
    if (std::distance(begin, end) <= 1) return;

    Iterator middle = begin + std::distance(begin, end) / 2;
    mergeInsertSort(begin, middle);
    mergeInsertSort(middle, end);

    std::inplace_merge(begin, middle, end);
}

template<typename Iterator>
void PmergeMe::insert(Iterator begin, Iterator end, typename std::iterator_traits<Iterator>::value_type value)
{
    Iterator pos = std::lower_bound(begin, end, value);
    std::rotate(pos, end, end + 1);
    *pos = value;
}

void PmergeMe::displayResults()
{
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size() && i < 5; ++i)
	{
        std::cout << vec[i] << " ";
    }
    if (vec.size() > 5) std::cout << "[...]";
    std::cout << std::endl;

    std::cout << "After: ";
    for (size_t i = 0; i < vec.size() && i < 5; ++i)
	{
        std::cout << vec[i] << " ";
    }
    if (vec.size() > 5) std::cout << "[...]";
    std::cout << std::endl;
}
