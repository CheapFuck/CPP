#include "Brain.hpp"

    // Default constructor
    Brain::Brain()
    {
         // Initialize the ideas array with default values (optional)
        for (int i = 0; i < 100; ++i) {
            ideas[i] = "Idea #" + std::to_string(i);  // Assigning a default idea (e.g., "Idea #0", "Idea #1", etc.)
        }
        std::cout << "Brain constructor called\n";
    }

    // Copy constructor
    Brain::Brain(const Brain& other)
    {
          for (int i = 0; i < 100; ++i) {
            this->ideas[i] = other.ideas[i];  // Copy each idea from the other Brain
        }
        std::cout << "Brain copy constructor called\n";
    }

    // Copy assignment operator
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

    // Destructor
    Brain::~Brain()
    {
        std::cout << "Brain destructor called\n";
    }

