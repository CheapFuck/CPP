#include "WrongAnimal.hpp"

// Constructors
WrongAnimal::WrongAnimal() : _type("WrongDefault")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}


// Animal::Animal(const std::string name) : _type(name)
// {
//         std::cout << "Animal parameterized constructor called for " << _type << std::endl;
// }


WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &other)
    {
    }
    return *this;
}

// Destructor
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called for " << _type << std::endl;
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

std::string WrongAnimal::getType(void) const
{
   return _type;
}


void WrongAnimal::makeSound() const
{
    std::cout << "Wrong *PIEP* *KWAF* *WIAUW* *PKRAAK*" <<  std::endl;
}
