#include <iostream>
#include <stack>


int main()
{
    std::stack<std::string> back_stack;
    std::stack<std::string> forward_stack;
    std::string temp;
    while (temp != "exit")
    {
        std::cout << "[1] visited URL     [2] Back     [3]Forward" << std::endl;
        std::cin >> temp;
       
        if (temp == "exit")
            break;
        if (temp == "1")
        {
            std::cout << "Enter URL:  ";
            std::cin >> temp;
            back_stack.push(temp);
            forward_stack = std::stack<std::string>();
        }
        else if (temp == "2")
        {
            std::cout << "Going back ...." << std::endl;
            forward_stack.push(back_stack.top());
            back_stack.pop();
        }
        else if (temp == "3")
        {
            if (forward_stack.empty())
                std::cout << "No history forward!" << std::endl;
            else
            {
                std::cout << "Going Forward ...." << std::endl;
                back_stack.push(forward_stack.top());
                forward_stack.pop();
            }
        }
        if (back_stack.empty())
        {
            std::cout << "No history" << std::endl;
            break;
        }
        std::cout << "Current URl: " << back_stack.top() << std::endl;     
    }
}