#include "Span.hpp"

Span::Span(unsigned int N) : _N(N)
{

}

Span::~Span()
{

}

void Span::addNumber(unsigned int num)
{
    if (_v.size() <= _N)
        _v.push_back(num);
    else
        throw outOfRange();
}

unsigned int Span::shortestSpan()
{
    std::vector<unsigned int>::iterator it1 = _v.begin();
    std::vector<unsigned int>::iterator it2;
    unsigned int min = 4294967295;

    for (it1 ;  it1 < _v.end(); it1++)
    {
        unsigned int temp = *it1;
        it2 = _v.begin() + 1;
        for (it2 ;  it2 < _v.end(); it2++)
        {
            temp -= *it2;
            if(temp < min)
                min = temp;
        }
    }
    return min;
}

unsigned int Span::longestSpan()
{
     if (_v.size() < 2)
        throw notFound();

    unsigned int min_val = *std::min_element(_v.begin(), _v.end());
    unsigned int max_val = *std::max_element(_v.begin(), _v.end());

    return max_val - min_val;
}

const char* Span::notFound:: what() const throw()
{
	return "Error: No span found";
};

const char* Span::outOfRange:: what() const throw()
{
	return "Exceeded maximum size of the vector";
};