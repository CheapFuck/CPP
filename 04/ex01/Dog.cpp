#include "Dog.hpp"

    // Default constructor
    Dog::Dog() : Animal()
    {
        _type = "Dog";
        this->brain = new Brain(); 
        std::cout << "Dog default constructor called" << std::endl;
    }

    // Copy constructor
    Dog::Dog(const Dog& other) : Animal(other)
    {
        _type = other._type;
        this->brain = new Brain();  // Allocate a new Brain for the copy
        *this->brain = *other.brain;  // 
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
            _type = other._type;  // Copy the type 
        }
        return *this;
    }

    // Destructor
    Dog::~Dog()
    {
        delete brain;
        std::cout << "Dog destructor called" << std::endl;
    }


void Dog::makeSound() const
{
    std::cout << "♫ Woef ♫" <<  std::endl;
}
