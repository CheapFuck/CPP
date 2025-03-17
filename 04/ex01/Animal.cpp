#include "Animal.hpp"

// Constructors
Animal::Animal()
{
    setType("Default");
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
    setType(other._type);
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _type = other._type;
    }
    return *this;
}

// Destructor
Animal::~Animal()
{
    std::cout << "Animal destructor called for " << _type << std::endl;
}

void Animal::setType(std::string name)
{
    _type = name;
}

std::string Animal::getType(void) const
{
   return _type;
}

void Animal::makeSound() const
{
    std::cout << "*PIEP* *KWAF* *WIAUW* *PKRAAK*" <<  std::endl;
}
