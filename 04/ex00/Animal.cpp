#include "Animal.hpp"

// Constructors
Animal::Animal() : type("Default")
{
    std::cout << "Animal default constructor called" << std::endl;
}


// Animal::Animal(const std::string name) : _type(name)
// {
//         std::cout << "Animal parameterized constructor called for " << _type << std::endl;
// }


Animal::Animal(const Animal& other)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
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

// Destructor
Animal::~Animal()
{
    std::cout << "Animal destructor called for " << type << std::endl;
}

// void Animal::setType(std::string name)
// {
//     _type = name;
// }

std::string Animal::getType(void) const
{
   return type;
}

void Animal::makeSound() const
{
    std::cout << "*PIEP* *KWAF* *WIAUW* *PKRAAK*" <<  std::endl;
}
