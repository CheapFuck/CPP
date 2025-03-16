#include "Animal.hpp"

// Constructors
Animal::Animal() : _type("Default")
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
    }
    return *this;
}

// Destructor
Animal::~Animal()
{
    std::cout << "Animal destructor called for " << _type << std::endl;
}


// #include "Animal.hpp"

// Animal::Animal()
// {
//     std::cout << "Animal default constructor called" << std::endl;
// }

// Animal::Animal(const std::string name) : _type(name)
// {}

// Animal::Animal(const Animal& other)
// {
//     std::cout << "Animal copy constructor called" << std::endl;
//     *this = other;
// }
// Animal& Animal::operator=(const Animal& other)
// {
//     std::cout << "Animal copy assignment operator called" << std::endl;
//     if (this != &other)
// 	{
//         _type = other._type;
//     }
//     return *this;
// }



// Animal::~Animal()
// {
//     std::cout << _type << " is being destroyed." << std::endl;
// }
// void Animal::setType(std::string name)
// {
//     _type = name;
// }

std::string Animal::getType(void) const
{
   return _type;
}


void Animal::makeSound() const
{
    std::cout << "*PIEP* *KWAF* *WIAUW* *PKRAAK*" <<  std::endl;
}
