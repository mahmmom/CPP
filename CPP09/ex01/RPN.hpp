#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <limits>


class RPN
{
    private:
        std::stack<int> _stack;
        bool isOperator(char c) const;
        int performOperation(int a, int b, char op) const;
    
    public:
        //Orthodox Canonical Form
        RPN();
        RPN(const RPN &copy);
        ~RPN();
        RPN &operator=(const RPN &copy);

        // Class methods Reversed Polish Notation
        int evaluate(const std::string& expression);


        // exceptions
        class NotEnoughOperands : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class DivisionByZero : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class InvalidInput : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class Overflow : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };






};

#endif