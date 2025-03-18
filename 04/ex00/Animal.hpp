#pragma once
#include <cstring>
#include <iostream>

class Animal
{

protected:
    std::string type;

public:
    Animal();                                 // Default constructor
    // Animal(const std::string _type);          // Parameterized constructor
    Animal(const Animal& other);            // Copy constructor
    Animal& operator=(const Animal& other); // Copy assignment operator
    virtual ~Animal();                                // Destructor

    void setType(std::string animal_name);
    std::string getType(void) const;

    virtual void makeSound() const;

};
