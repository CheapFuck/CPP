#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    // Default constructor
    WrongCat();
    // Cat(const std::string& value);
    WrongCat(const WrongCat& other);
    WrongCat& operator=(const WrongCat& other);
    ~WrongCat() override;

    void makeSound() const override;

};
