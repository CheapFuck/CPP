#pragma once
#include "Animal.hpp"

class Cat : public Animal
{
public:
    // Default constructor
    Cat();
    // Cat(const std::string& value);
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat() override;

    void makeSound() const override;

};
