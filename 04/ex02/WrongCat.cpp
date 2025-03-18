#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    type = "WrongCat";
    this->brain = new Brain();
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
    type = other.type;
    this->brain = new Brain();
    *this->brain = *other.brain;
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        WrongAnimal::operator=(other);
        type = other.type;
    }
    return *this;
}

WrongCat::~WrongCat()
{
    delete brain;
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "♫ WrongMiauw ♫" <<  std::endl;
}
