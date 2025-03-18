#pragma once
#include <cstring>
#include <iostream>

class Animal
{

protected:
    std::string type;

public:
    Animal();                                 // Default constructor
    Animal(const Animal& other);            // Copy constructor
    Animal& operator=(const Animal& other); // Copy assignment operator
    virtual ~Animal();                                // Destructor

    void setType(std::string animal_type);
    const std::string& getType(void) const;
    // Return a reference to the type (this avoids returning a temporary)
    // const std::string& getType() const { return type; }
    virtual void makeSound() const;

};
