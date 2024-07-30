#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

template<typename T>
void swap(T & a, T & b)
{
	T temp = a;
	a = b;
	b = temp;
};

template<typename T>
T const& min(T const& a, T const& b)
{
	return ((a < b) ? a : b);
};

template<typename T>
T const& max(T const& a, T const& b)
{
	return ((a > b) ? a : b);
};

#endif