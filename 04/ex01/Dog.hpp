#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain* brain;
public:
    // Default constructor
    Dog();
    // Cat(const std::string& value);
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog() override;

    void makeSound() const override;
};
