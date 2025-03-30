#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    this->brain = new Brain(); 
    // std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    type = other.type;
    this->brain = new Brain();
    *this->brain = *other.brain;
    // std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    // std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        type = other.type;
    }
    return *this;
}

Dog::~Dog()
{
    delete brain;
    // std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "♫ Woef ♫" <<  std::endl;
}
