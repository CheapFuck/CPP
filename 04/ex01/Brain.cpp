#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; ++i)
    {
        ideas[i] = "Idea #" + std::to_string(i);
    }
    std::cout << "Brain constructor called\n";
}

Brain::Brain(const Brain& other)
{
    for (int i = 0; i < 100; ++i)
    {
        this->ideas[i] = other.ideas[i];
    }
    std::cout << "Brain copy constructor called\n";
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i)
        {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called\n";
}

