#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <utility>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <ctime>
#include <exception>

class PmergeMe
{
	private:
		std::vector<int> vec;
		std::list<int> lst;
		bool isNumber(std::string& str);
		template <typename Container>
		Container mergeInsertSort(Container& container);
		template <typename Container>
		std::vector<std::pair<int, int> > createPairs(const Container& container);
		void sortPair(std::pair<int, int>& pair);
		template <typename Container>
		Container insertSmallerElements(const Container& sorted, Container smaller);
		std::vector<int> buildJacobsthalSequence(size_t n);
		int jacobsthal(int n);

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

		void parseInput(int argc, char* argv[]);
		void sort();
		void displayResults() const;

		class invalidInput : public std::exception
		{
			const char* what() const throw();
		};
};


#endif