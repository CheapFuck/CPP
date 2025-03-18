#pragma once
#include <cstring>
#include <iostream>

class WrongAnimal
{

protected:
    std::string _type;

public:
    WrongAnimal();                                 // Default constructor
    // Animal(const std::string _type);          // Parameterized constructor
    WrongAnimal(const WrongAnimal& other);            // Copy constructor
    WrongAnimal& operator=(const WrongAnimal& other); // Copy assignment operator
    virtual ~WrongAnimal();                                // Destructor

    void setType(std::string Wrong_animal_name);
    std::string getType(void) const;

    /*virtual*/void makeSound() const;

};
