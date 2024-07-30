#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <exception>

// containers
#include <vector>
#include <deque>
#include <list>
#include <set>

//      Colors
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

//      Exception


//      Class
class Span
{
    private:
        unsigned int _N;
        std::vector<unsigned int> _v;
        Span();

    public:
        Span(unsigned int N);
        ~Span();
        unsigned int shortestSpan();
        unsigned int longestSpan();
        void    addNumber(unsigned int num);


    class notFound : public std::exception
    {
        public:
		    const char* what() const throw();
    };

    class outOfRange : public std::exception
    {
        public:
		    const char* what() const throw();
    };
};


#endif

