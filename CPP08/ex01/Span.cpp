#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <vector>


Span::Span() : _N(0)
{

}

Span::Span(unsigned int N) : _N(N)
{

}

Span::Span(const Span& other) 
{
	*this = other;
}

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->_N = other._N;
		this->_v = other._v;
	}
	return *this;
}

Span::~Span(){}

void Span::addNumber(int num)
{
	if(_v.size() == _N)
		throw outOfRange();
	// if (num < 0)
	// 	throw std::runtime_error("Number is Negative");
	_v.push_back(num);
}

unsigned int Span::shortestSpan()
{
    if (_v.size() < 2)
        throw outOfRange();

    std::sort(_v.begin(), _v.end());
    std::vector<int>::iterator it = _v.begin();
    unsigned int min = *(it + 1) - *it;

    for (it = _v.begin() + 1; it != _v.end() - 1; ++it)
    {
        unsigned int span = *(it + 1) - *it;
        if (span < min)
            min = span;
    }
    return min;
}

unsigned int Span::longestSpan()
{
    if (_v.size() < 2)
	 throw notFound();
	return(*std::max_element(_v.begin(), _v.end()) - *std::min_element(_v.begin(), _v.end()));
}

void	Span::addRandomNumbers(int size)
{
	if (size < 0)
		throw std::runtime_error("Size cant be Negative");
	std::srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < size; i++)
	{
		_v.insert(_v.end(), rand() % 1000);
	}
}

unsigned int 	Span::getSize() const
{
	return _N;
}

std::vector<int> Span::getVector() const
{
	return _v;
}

const char* Span::notFound:: what() const throw()
{
	return "Error: No span found";
};

const char* Span::outOfRange:: what() const throw()
{
	return "Exceeded maximum size of the vector";
};