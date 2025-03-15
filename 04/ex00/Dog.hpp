#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
public:
    // Default constructor
    Dog();
    // Cat(const std::string& value);
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog() override;

    void makeSound() const override;
};
