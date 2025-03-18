#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongDefault")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

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

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called for " << type << std::endl;
}

std::string WrongAnimal::getType(void) const
{
   return type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Wrong *PIEP* *KWAF* *WIAUW* *PKRAAK*" <<  std::endl;
}
