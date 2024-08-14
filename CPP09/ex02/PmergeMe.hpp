#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <ctime>
#include <iostream>

class PmergeMe
{
	private:
		std::vector<int> vec;
		std::deque<int> deq;

		void sortVector();
		void sortDeque();
		
		template<typename Iterator>
		void mergeInsertSort(Iterator begin, Iterator end);
		
		template<typename Iterator>
		void insert(Iterator begin, Iterator end, typename std::iterator_traits<Iterator>::value_type value);

	public:
		PmergeMe();
		~PmergeMe();

		void parseInput(int argc, char* argv[]);
		void sort();
		void displayResults();
};

#endif