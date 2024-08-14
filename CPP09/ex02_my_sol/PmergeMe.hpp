#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <string>
#include <ctime>
#include <iostream>
#include <exception>
#include <cctype>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <algorithm>

class PmergeMe
{
private:
    std::vector<int> vec;
    std::list<int> lst;
    int tempVec;
    int tempLst;

    // Helper functions for Ford-Johnson algorithm
    std::vector<std::pair<int, int> > createPairs(std::vector<int>& container);
    std::list<std::pair<int, int> > createPairs(std::list<int>& container);
    
    void sortEachPair(std::vector<std::pair<int, int> >& container);
    void sortEachPair(std::list<std::pair<int, int> >& container);
    
    void sortByLargerValue(std::vector<std::pair<int, int> >& container);
    void sortByLargerValue(std::list<std::pair<int, int> >& container);
    
    std::vector<int> createS(std::vector<std::pair<int, int> >& container, int straggler);
    std::list<int> createS(std::list<std::pair<int, int> >& container, int straggler);
    
    std::vector<int> buildJacobInsertionSequence(int size);
    int jacobsthal(int n);
    
    void insertionSort(std::vector<int>& container);
    void insertionSort(std::list<int>& container);

public:
    // Canonical form
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void parseInput(int argc, char* argv[]);
    void sort();
    void displayResults();

    class invalidInput : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

#endif