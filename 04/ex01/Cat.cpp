#include "Cat.hpp"

 Cat::Cat() : Animal()
{
    type = "Cat";
    this->brain = new Brain();
    // std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    type = other.type;
    this->brain = new Brain();
    *this->brain = *other.brain;
    // std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    // std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        type = other.type;
    }
   return *this;
}

Cat::~Cat()
{
    delete brain;
    // std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "♫ Miauw ♫" <<  std::endl;
}
