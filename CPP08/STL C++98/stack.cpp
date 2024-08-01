#include <iostream>
#include <stack>


int main()
{
    std::stack<int> numbers;
    int temp = 0;

	numbers.swap(stack<int> &s)

    std::cout << ".....Push to stack....." << std::endl;
    while (temp >= 0)
    {
        std::cout << "Enter a number:  ";
        std::cin >> temp;
        if (temp >= 0)
            numbers.push(temp);
    }
    
    std::cout << "=====Printing Stack=====" << std::endl;
    std::cout << "{ ";
    while(!numbers.empty() && numbers.size() > 0)
    {
        std::cout << numbers.top() << " ";
        numbers.pop();
    }
    std::cout << "}" << std::endl;
    if(!numbers.empty())
        std::cout << numbers.top() << std::endl;
    else
        std::cout << "stack is empty" << std::endl;
}