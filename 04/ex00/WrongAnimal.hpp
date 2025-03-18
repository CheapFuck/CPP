#pragma once
#include <cstring>
#include <iostream>

class WrongAnimal
{

protected:
    std::string type;

public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    /*virtual*/~WrongAnimal();

    void setType(std::string Wrong_animal_name);
    std::string getType(void) const;
    /*virtual*/ void makeSound() const;
};
