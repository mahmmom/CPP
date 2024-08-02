#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <exception>

// containers
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <stack>

//      Colors
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;

		MutantStack(): std::stack<T>(){}
		~MutantStack(){}
		MutantStack(const MutantStack<T>& src) : std::stack<T>(src){}
		MutantStack<T>& operator=(const MutantStack<T>& other)
		{
			if (this != &other)
				std::stack<T>::operator=(other);
			return *this;
		}
		iterator begin()
		{
			return this->c.begin();
		}
		iterator end()
		{
			return this->c.end();
		}
};

#endif