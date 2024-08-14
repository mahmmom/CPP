#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe()
{

}

/*=============================================================================================================*/

void PmergeMe::parseInput(int argc, char* argv[])
{
	long long int num;
	for (int i = 1; i < argc; i++)
	{
		std::string str = argv[i];
		if (str.find_first_not_of("0123456789") != std::string::npos || str.empty())
			throw invalidInput();
		num = std::stoll(str);
		if (num < 1)
			throw invalidInput();
		vec.push_back(num);
		lst.push_back(num);
	}
}

void PmergeMe::displayResults()
{
	std::cout << "Vector: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "List: ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}



std::vector<std::pair<int, int> > PmergeMe::createPairs(std::vector<int>& container)
{
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < container.size(); i += 2)
	{
		if (i + 1 < container.size())
            pairs.push_back(std::make_pair(container[i], container[i + 1]));
		else
            pairs.push_back(std::make_pair(container[i], -1)); // Straggler
    }
    return pairs;
}

std::list<std::pair<int, int> > PmergeMe::createPairs(std::list<int>& container)
{
    std::list<std::pair<int, int> > pairs;
    std::list<int>::iterator it = container.begin();
    while (it != container.end())
	{
        int first = *it++;
		if (it != container.end())
		{
            int second = *it++;
            pairs.push_back(std::make_pair(first, second));
        }
		else
            pairs.push_back(std::make_pair(first, -1)); // Straggler
    }
    return pairs;
}

void PmergeMe::sortEachPair(std::vector<std::pair<int, int> >& container)
{
    for (size_t i = 0; i < container.size(); ++i)
	{
        if (container[i].second != -1 && container[i].first > container[i].second)
            std::swap(container[i].first, container[i].second);
    }
}

void PmergeMe::sortEachPair(std::list<std::pair<int, int> >& container)
{
    for (std::list<std::pair<int, int> >::iterator it = container.begin(); it != container.end(); ++it)
	{
        if (it->second != -1 && it->first > it->second)
            std::swap(it->first, it->second);
    }
}

bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
    return a.second < b.second;
}

void PmergeMe::sortByLargerValue(std::vector<std::pair<int, int> >& container)
{
    std::sort(container.begin(), container.end(), comparePairs);
}

void PmergeMe::sortByLargerValue(std::list<std::pair<int, int> >& container)
{
    container.sort(comparePairs);
}

std::vector<int> PmergeMe::createS(std::vector<std::pair<int, int> >& container, int straggler)
{
    std::vector<int> S;
    std::vector<int> pend;
    
    for (size_t i = 0; i < container.size(); ++i)
	{
        S.push_back(container[i].second);
        if (container[i].first != -1)
            pend.push_back(container[i].first);
    }
    
    if (!pend.empty())
	{
        S.insert(S.begin(), pend[0]);
        pend.erase(pend.begin());
    }
    
    std::vector<int> insertionSequence = buildJacobInsertionSequence(pend.size());
    
    for (size_t i = 0; i < insertionSequence.size(); ++i)
	{
        std::vector<int>::iterator it = std::lower_bound(S.begin(), S.end(), pend[insertionSequence[i] - 1]);
        S.insert(it, pend[insertionSequence[i] - 1]);
    }
    
    if (straggler != -1)
	{
        std::vector<int>::iterator it = std::lower_bound(S.begin(), S.end(), straggler);
        S.insert(it, straggler);
    }
    
    return S;
}

std::list<int> PmergeMe::createS(std::list<std::pair<int, int> >& container, int straggler)
{
    std::list<int> S;
    std::list<int> pend;
    
    for (std::list<std::pair<int, int> >::iterator it = container.begin(); it != container.end(); ++it)
	{
        S.push_back(it->second);
        if (it->first != -1)
            pend.push_back(it->first);
    }
    
    if (!pend.empty())
	{
        S.push_front(pend.front());
        pend.pop_front();
    }
    
    std::vector<int> insertionSequence = buildJacobInsertionSequence(pend.size());
    
    for (size_t i = 0; i < insertionSequence.size(); ++i)
	{
        std::list<int>::iterator pendIt = pend.begin();
        std::advance(pendIt, insertionSequence[i] - 1);
        
        std::list<int>::iterator it = std::lower_bound(S.begin(), S.end(), *pendIt);
        S.insert(it, *pendIt);
    }
    
    if (straggler != -1)
	{
        std::list<int>::iterator it = std::lower_bound(S.begin(), S.end(), straggler);
        S.insert(it, straggler);
    }
    
    return S;
}

std::vector<int> PmergeMe::buildJacobInsertionSequence(int size)
{
    std::vector<int> sequence;
    int i = 2;
    while (jacobsthal(i) <= size)
	{
        sequence.push_back(jacobsthal(i));
        i++;
    }

    for (int j = jacobsthal(i - 1) + 1; j <= size; j++)
	{
        sequence.push_back(j);
    }
    return sequence;
}

int PmergeMe::jacobsthal(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void PmergeMe::sort()
{
    // Vector sorting
    if (vec.size() > 1) {
        tempVec = vec.size() % 2 ? vec.back() : -1;
        if (tempVec != -1) vec.pop_back();

        std::vector<std::pair<int, int> > vecPairs = createPairs(vec);
        sortEachPair(vecPairs);
        sortByLargerValue(vecPairs);
        vec = createS(vecPairs, tempVec);
    }

    // List sorting
    if (lst.size() > 1) {
        tempLst = lst.size() % 2 ? lst.back() : -1;
        if (tempLst != -1) lst.pop_back();

        std::list<std::pair<int, int> > lstPairs = createPairs(lst);
        sortEachPair(lstPairs);
        sortByLargerValue(lstPairs);
        lst = createS(lstPairs, tempLst);
    }
}


/*===================== Exceptions =================================*/

const char *PmergeMe::invalidInput::what() const throw()
{
	return "Invalid input: Please provide a sequence of positive integers.";
}
