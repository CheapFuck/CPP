#include "Cat.hpp"
#include <iostream>

    // Default constructor
    Cat::Cat() : Animal()
    {
        type = "Cat";
        std::cout << "Cat default constructor called" << std::endl;
    }

    // Parameterized constructor
    // Cat::Cat(const std::string& value) : Animal(value)
    // {
    // //    _type = value;
    //    _type = "Cat";
    //    std::cout << "Cat parameterized constructor called for " << value << std::endl;

    // }

    // Copy constructor
    Cat::Cat(const Cat& other)
    {
        std::cout << "Cat copy constructor called" << std::endl;
        *this = other;
    }

    // Copy assignment operator
    Cat& Cat::operator=(const Cat& other)
    {
        std::cout << "Cat copy assignment operator called" << std::endl;
        if (this != &other)
        {
            Animal::operator=(other);  // Call the base class assignment operator
            type = other.type;  // Copy the type 
        }
        return *this;
    }

    // Destructor
    Cat::~Cat()
    {
        std::cout << "Cat destructor called" << std::endl;
    }


void Cat::makeSound() const
{
    std::cout << "♫ Miauw ♫" <<  std::endl;
}
