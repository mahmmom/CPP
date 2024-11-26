#include "RPN.hpp"

// Orthodox Canonical Form

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &copy)
{
    *this = copy;
}

RPN &RPN::operator=(const RPN &copy)
{
    if (this != &copy)
    {
        this->_stack = copy._stack;
    }
    return *this;
}

// Class methods Reversed Polish Notation
int RPN::evaluate(const std::string& expression)
{
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token)
    {
        if (token.size() == 1 && isOperator(token[0]))
        {
            if (_stack.size() < 2)
                throw NotEnoughOperands();
            int a = _stack.top();
            _stack.pop();
            int b = _stack.top();
            _stack.pop();
            _stack.push(performOperation(a, b, token[0]));
        }
        else
        {
            int number;
            std::stringstream numStream(token);
            if (!(numStream >> number))
                throw InvalidInput();
            _stack.push(number);
        }
    }
    if (_stack.size() != 1)
        throw InvalidInput();
    // check for overflow
    if (_stack.top() < 0)
        throw Overflow();
    // how to know if the result is overflow? because I'm not allowed to use long long
    if (_stack.top() > INT_MAX)
        throw Overflow();
    return _stack.top();
}

bool RPN::isOperator(char c) const
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::performOperation(int a, int b, char op) const
{
    switch (op)
    {
        case '+':
            return a + b;
        case '-':
            return b - a;
        case '*':
            return a * b;
        case '/': 
            if (a == 0)
                throw DivisionByZero();
            return b / a;
        default:
            throw InvalidInput();
    }
}

// exceptions
const char *RPN::NotEnoughOperands::what() const throw()
{
    return "Error: Not enough operands";
}

const char *RPN::DivisionByZero::what() const throw()
{
    return "Error: Division by zero";
}

const char *RPN::InvalidInput::what() const throw()
{
    return "Error: Invalid input";
}

const char *RPN::Overflow::what() const throw()
{
    return "Error: Overflow";
}
