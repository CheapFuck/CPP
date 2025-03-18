#include "Animal.hpp"

Animal::Animal()
{
    setType("Default");
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
    setType(other.type);
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &other)
    {
        type = other.type;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called for " << type << std::endl;
}

void Animal::setType(std::string name)
{
    type = name;
}

const std::string& Animal::getType(void) const
{
   return type;
}

void Animal::makeSound() const
{
    std::cout << "*PIEP* *KWAF* *WIAUW* *PKRAAK*" <<  std::endl;
}
