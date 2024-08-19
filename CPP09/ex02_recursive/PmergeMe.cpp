#include "PmergeMe.hpp"
#include <iomanip>


PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) : vec(other.vec), lst(other.lst) {}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other) {
        vec = other.vec;
        lst = other.lst;
    }
    return *this;
}

bool PmergeMe::isNumber(std::string& str)
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

void PmergeMe::parseInput(int argc, char* argv[])
{
    for (int i = 1; i < argc; ++i)
	{
		std::string str = argv[i];
		if (!isNumber(str) || str.empty())
			throw invalidInput();
        double num = std::strtod(str.c_str(),NULL);
		if (num <=0 || num != static_cast<int>(num))
			throw invalidInput();
       
		vec.push_back(num);
		lst.push_back(num);
    }
}

void PmergeMe::displayResults() const
{
    std::cout << "Vector: ";
    for (size_t i = 0; i < vec.size(); ++i)
	{
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "List: ";
    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
	{
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::sort()
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    vec = mergeInsertSort(vec);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    std::cout  << std::fixed << "Time to process a range of " << vec.size() 
              << " elements with std::vector : "  << cpu_time_used  << " us" << std::endl;

    start = clock();
    lst = mergeInsertSort(lst);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    std::cout << std::fixed << "Time to process a range of " << lst.size() 
              << " elements with std::list : " << cpu_time_used  << " us" << std::endl;
}

template <typename Container>
Container PmergeMe::mergeInsertSort(Container& container)
{
    if (container.size() <= 1)
		return container;

    std::vector<std::pair<int, int> > pairs = createPairs(container);

    for (size_t i = 0; i < pairs.size(); ++i)
	{
        sortPair(pairs[i]);
    }

    Container largerElements;
    Container smallerElements;

    for (size_t i = 0; i < pairs.size(); ++i)
	{
		if (pairs[i].second != -1)
		{
            largerElements.push_back(pairs[i].second);
            smallerElements.push_back(pairs[i].first);
        }
		else
		{
            largerElements.push_back(pairs[i].first);
        }
    }
    largerElements = mergeInsertSort(largerElements);
    return insertSmallerElements(largerElements, smallerElements);
}

template <typename Container>
std::vector<std::pair<int, int> > PmergeMe::createPairs(const Container& container)
{
    std::vector<std::pair<int, int> > pairs;
    typename Container::const_iterator it = container.begin();
    
    while (it != container.end())
	{
        int first = *it++;
		if (it != container.end())
		{
            int second = *it++;
            pairs.push_back(std::make_pair(first, second));
        }
		else
		{
            pairs.push_back(std::make_pair(first, -1)); // Straggler
        }
    }
    return pairs;
}

void PmergeMe::sortPair(std::pair<int, int>& pair)
{
    if (pair.second != -1 && pair.first > pair.second)
	{
        std::swap(pair.first, pair.second);
    }
}

template <typename Container>
Container PmergeMe::insertSmallerElements(const Container& sorted, const Container& smaller)
{
    Container result = sorted;
    if (smaller.empty())
        return result;

    std::set<typename Container::value_type> insertedElements(result.begin(), result.end());

    typename Container::const_iterator firstIt = smaller.begin();
    if (insertedElements.find(*firstIt) == insertedElements.end())
    {
        typename Container::iterator insertPos = std::lower_bound(result.begin(), result.end(), *firstIt);
        result.insert(insertPos, *firstIt);
        insertedElements.insert(*firstIt);
    }

    std::vector<int> jacobsthalSeq = buildJacobsthalSequence(smaller.size());
    
    for (size_t i = 1; i < jacobsthalSeq.size(); ++i)
    {
        if (static_cast<unsigned long>(jacobsthalSeq[i] - 1) >= smaller.size())
            break;

        typename Container::const_iterator it = smaller.begin();
        std::advance(it, jacobsthalSeq[i] - 1);
        if (insertedElements.find(*it) == insertedElements.end())
        {
            typename Container::iterator insertPos = std::lower_bound(result.begin(), result.end(), *it);
            result.insert(insertPos, *it);
            insertedElements.insert(*it);
        }
    }

    for (typename Container::const_iterator it = smaller.begin(); it != smaller.end(); ++it)
    {
        if (insertedElements.find(*it) == insertedElements.end())
        {
            typename Container::iterator insertPos = std::lower_bound(result.begin(), result.end(), *it);
            result.insert(insertPos, *it);
            insertedElements.insert(*it);
        }
    }

    return result;
}


std::vector<int> PmergeMe::buildJacobsthalSequence(size_t n)
{
    std::vector<int> sequence;
    int i = 0;
    while (jacobsthal(i) < static_cast<int>(n))
	{
        sequence.push_back(jacobsthal(i));
        ++i;
    }
    return sequence;
}

int PmergeMe::jacobsthal(int n)
{
    if (n == 0)
		return 0;
    if (n == 1)
		return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

const char* PmergeMe::invalidInput::what() const throw()
{
	return "Invalid input";
}