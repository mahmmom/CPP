#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
    for (int i = 0; i < 100; ++i)
    {
        ideas[i] = "default idea";
    }
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i)
        {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

std::string     Brain::getIdea(int pos) const
{
    if(pos > 99 || pos < 0)
    {
        return "Error position out of range";
    }
    return ideas[pos];
}

void Brain::setIdea(int pos, const std::string& newIdea)
{
	if(pos > 99 || pos < 0)
    {
        std::cout << "Error position out of range" << std::endl;
        return ;
    }
    ideas[pos] = newIdea;
}
