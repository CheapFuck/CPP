#pragma once
#include <cstring>
#include <iostream>

class Animal
{

protected:
    std::string type;

public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();

    void setType(std::string animal_type);
    const std::string& getType(void) const;
    virtual void makeSound() const;
};
