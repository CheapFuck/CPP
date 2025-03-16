#include "WrongCat.hpp"
#include <iostream>

    // Default constructor
    WrongCat::WrongCat() : WrongAnimal()
    {
        _type = "WrongCat";
        this->brain = new Brain();  // Allocate a new Brain for this Cat
        std::cout << "WrongCat default constructor called" << std::endl;
    }

    // Parameterized constructor
    // Cat::Cat(const std::string& value) : Animal(value)
    // {
    // //    _type = value;
    //    _type = "Cat";
    //    std::cout << "Cat parameterized constructor called for " << value << std::endl;

    // }

    // Copy constructor
    WrongCat::WrongCat(const WrongCat& other)
    {
        _type = other._type;
        this->brain = new Brain();  // Allocate a new Brain for the copy
        *this->brain = *other.brain;  // 
        std::cout << "WrongCat copy constructor called" << std::endl;
        *this = other;
    }

    // Copy assignment operator
    WrongCat& WrongCat::operator=(const WrongCat& other)
    {
        std::cout << "WrongCat copy assignment operator called" << std::endl;
        if (this != &other)
        {
            WrongAnimal::operator=(other);  // Call the base class assignment operator
            _type = other._type;  // Copy the type 
        }
        return *this;
    }

    // Destructor
    WrongCat::~WrongCat()
    {
        delete brain;
        std::cout << "WrongCat destructor called" << std::endl;
    }


void WrongCat::makeSound() const
{
    std::cout << "♫ WrongMiauw ♫" <<  std::endl;
}
