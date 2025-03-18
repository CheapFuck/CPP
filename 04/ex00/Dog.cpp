#include "Dog.hpp"

    // Default constructor
    Dog::Dog() : Animal()
    {
        type = "Dog";
        std::cout << "Dog default constructor called" << std::endl;
    }

    // Copy constructor
    Dog::Dog(const Dog& other) : Animal(other)
    {
        type = other.type;
        std::cout << "Dog copy constructor called" << std::endl;
        // *this = other;
    }

    // Copy assignment operator
    Dog& Dog::operator=(const Dog& other)
    {
        std::cout << "Dog copy assignment operator called" << std::endl;
        if (this != &other)
        {
            Animal::operator=(other);  // Call the base class assignment operator
            type = other.type;  // Copy the type 
        }
        return *this;
    }

    // Destructor
    Dog::~Dog()
    {
        std::cout << "Dog destructor called" << std::endl;
    }


void Dog::makeSound() const
{
    std::cout << "♫ Woef ♫" <<  std::endl;
}
